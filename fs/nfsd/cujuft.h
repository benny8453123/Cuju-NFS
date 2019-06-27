#include <linux/list.h>
#include <linux/types.h>

#include "nfsfh.h"
#include "nfsd.h"
#include "xdr4.h"

struct nfsd4_cuju_write_request {
	u32 				cmd;			/* Request for distinguish cuju command */
	//rqstp
	unsigned long		rq_flags;
	u32					rq_vers;
	//fhp
	int					use_wgather;
	int					sync;
	//struct svc_fh 		*current_fh;
	//file
	struct file 		*file;
	//nfsd_write
	u64					wr_offset;
	u32					wr_buflen;
	u32					wr_how_written;
	//kvec
	struct kvec 		*vec;			/* The real write data vec */
	int 				nvecs;			/* How many vec in vec */
	int					epoch;
	//linked-list
	struct list_head 	list;			/* Link ft/write request/epoch in list */
};

/* nfs4proc.c */
__be32
nfsd4_cuju_fake_vfs_write(struct svc_rqst *rqstp, struct svc_fh *fhp, struct file *file,
		struct kvec *vec, int vlen,
		unsigned long *cnt, struct nfsd4_write *write);
__be32
nfsd4_cuju_check_fast_read(struct file *file, loff_t offset, struct kvec *vec, int vlen, unsigned long count);
__be32
nfsd4_cuju_do_fast_read(struct file *file, loff_t offset, struct kvec *vec, unsigned long count);
__be32
nfsd4_cuju_copy_to_vec(struct kvec *dest_vec, int dest_vlen, unsigned long dest_count, struct kvec *src_vec);
/* vfs.c */
__be32
nfsd4_cuju_vfs_write(struct nfsd4_cuju_write_request *req, unsigned long *cnt);
