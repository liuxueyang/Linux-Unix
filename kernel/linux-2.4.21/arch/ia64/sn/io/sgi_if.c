/* $Id$
 *
 * This file is subject to the terms and conditions of the GNU General Public
 * License.  See the file "COPYING" in the main directory of this archive
 * for more details.
 *
 * Copyright (C) 1992-1997,2000-2002 Silicon Graphics, Inc. All rights reserved.
 */

#include <linux/types.h>
#include <linux/ctype.h>
#include <linux/mm.h>
#include <linux/slab.h>
#include <asm/sn/sgi.h>
#include <asm/sn/invent.h>
#include <asm/sn/hcl.h>
#include <asm/sn/labelcl.h>
#include <asm/sn/pci/bridge.h>
#include <asm/sn/ioerror_handling.h>
#include <asm/sn/pci/pciio.h>
#include <asm/sn/slotnum.h>

unsigned char Is_pic_on_this_nasid[512];	/* non-0 when this is a pic shub */

void *
snia_kmem_zalloc(size_t size, int flag)
{
        void *ptr = kmalloc(size, GFP_KERNEL);
	if ( ptr )
        	BZERO(ptr, size);
        return(ptr);
}

void
snia_kmem_free(void *ptr, size_t size)
{
        kfree(ptr);
}

int
nic_vertex_info_match(devfs_handle_t v, char *s)
{
	/* we don't support this */
	return(0);
}

/*
 * the alloc/free_node routines do a simple kmalloc for now ..
 */
void *
snia_kmem_alloc_node(register size_t size, register int flags, cnodeid_t node)
{
	/* someday will Allocate on node 'node' */
	return(kmalloc(size, GFP_KERNEL));
}

void *
snia_kmem_zalloc_node(register size_t size, register int flags, cnodeid_t node)
{
	void *ptr = kmalloc(size, GFP_KERNEL);
	if ( ptr )
		BZERO(ptr, size);
        return(ptr);
}


#define xtod(c)         ((c) <= '9' ? '0' - (c) : 'a' - (c) - 10)
long
atoi(register char *p)
{
        register long n;
        register int c, neg = 0;

        if (p == NULL)
                return 0;

        if (!isdigit(c = *p)) {
                while (isspace(c))
                        c = *++p;
                switch (c) {
                case '-':
                        neg++;
                case '+': /* fall-through */
                        c = *++p;
                }
                if (!isdigit(c))
                        return (0);
        }
        if (c == '0' && *(p + 1) == 'x') {
                p += 2;
                c = *p;
                n = xtod(c);
                while ((c = *++p) && isxdigit(c)) {
                        n *= 16; /* two steps to avoid unnecessary overflow */
                        n += xtod(c); /* accum neg to avoid surprises at MAX */
                }
        } else {
                n = '0' - c;
                while ((c = *++p) && isdigit(c)) {
                        n *= 10; /* two steps to avoid unnecessary overflow */
                        n += '0' - c; /* accum neg to avoid surprises at MAX */
                }
        }
        return (neg ? n : -n);
}

char *
strtok_r(char *string, const char *sepset, char **lasts)
{
        register char   *q, *r;

        /*first or subsequent call*/
        if (string == NULL)
                string = *lasts;

        if(string == 0)         /* return if no tokens remaining */
                return(NULL);

        q = string + strspn(string, sepset);    /* skip leading separators */

        if(*q == '\0') {                /* return if no tokens remaining */
                *lasts = 0;     /* indicate this is last token */
                return(NULL);
        }

        if((r = strpbrk(q, sepset)) == NULL)    /* move past token */
                *lasts = 0;     /* indicate this is last token */
        else {
                *r = '\0';
                *lasts = r+1;
        }
        return(q);
}

/*
 * print_register() allows formatted printing of bit fields.  individual
 * bit fields are described by a struct reg_desc, multiple bit fields within
 * a single word can be described by multiple reg_desc structures.
 * %r outputs a string of the format "<bit field descriptions>"
 * %R outputs a string of the format "0x%x<bit field descriptions>"
 *
 * The fields in a reg_desc are:
 *	unsigned long long rd_mask; An appropriate mask to isolate the bit field
 *				within a word, and'ed with val
 *
 *	int rd_shift;		A shift amount to be done to the isolated
 *				bit field.  done before printing the isolate
 *				bit field with rd_format and before searching
 *				for symbolic value names in rd_values
 *
 *	char *rd_name;		If non-null, a bit field name to label any
 *				out from rd_format or searching rd_values.
 *				if neither rd_format or rd_values is non-null
 *				rd_name is printed only if the isolated
 *				bit field is non-null.
 *
 *	char *rd_format;	If non-null, the shifted bit field value
 *				is printed using this format.
 *
 *	struct reg_values *rd_values;	If non-null, a pointer to a table
 *				matching numeric values with symbolic names.
 *				rd_values are searched and the symbolic
 *				value is printed if a match is found, if no
 *				match is found "???" is printed.
 *				
 */

void
print_register(unsigned long long reg, struct reg_desc *addr)
{
	register struct reg_desc *rd;
	register struct reg_values *rv;
	unsigned long long field;
	int any;

	printk("<");
	any = 0;
	for (rd = addr; rd->rd_mask; rd++) {
		field = reg & rd->rd_mask;
		field = (rd->rd_shift > 0) ? field << rd->rd_shift : field >> -rd->rd_shift;
		if (any && (rd->rd_format || rd->rd_values || (rd->rd_name && field)))
			printk(",");
		if (rd->rd_name) {
			if (rd->rd_format || rd->rd_values || field) {
				printk("%s", rd->rd_name);
				any = 1;
			}
			if (rd->rd_format || rd->rd_values) {
				printk("=");
				any = 1;
			}
		}
		/* You can have any format so long as it is %x */
		if (rd->rd_format) {
			printk("%llx", field);
			any = 1;
			if (rd->rd_values)
				printk(":");
		}
		if (rd->rd_values) {
			any = 1;
			for (rv = rd->rd_values; rv->rv_name; rv++) {
				if (field == rv->rv_value) {
					printk("%s", rv->rv_name);
					break;
				}
			}
			if (rv->rv_name == NULL)
				printk("???");
		}
	}
	printk(">\n");
}
