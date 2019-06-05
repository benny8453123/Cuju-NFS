#include "nfsfh.h"
#include "nfsd.h"
#include "xdr4.h"

struct nfsd4_cuju_write_request {
	int 			cmd;		/* write request or epoch tag */
	//rqstp
	unsigned long	rq_flags;	/*  */
	u32			rq_vers;
	//fhp
	struct svc_fh *current_fh;
	//file
	struct file *file;
	//nfsd_write
	u64			wr_offset;
	u32			wr_buflen;
	u32			wr_how_written;
	//kvec
	struct kvec *vec;
	int nvecs;
};

__be32  nfsd4_cuju_vfs_write(struct nfsd4_cuju_write_request *req, unsigned long *cnt);
void*                                                                                       
nfsd4_cuju_fake_vfs_write(struct svc_rqst *rqstp, struct svc_fh *fhp, struct file *file,
		struct kvec *vec, int vlen,
		unsigned long *cnt, struct nfsd4_write *write,int cmd);
