/* For Cuju :
 * Define Cuju command for Cuju nfs/nfsd function
 * who need to distinguish command type 
 * should include this file
 */
enum nfs_cuju_cmd_ft {
	NFS_CUJU_CMD_NONE	=	0,
	NFS_CUJU_CMD_FT		=	1,
	NFS_CUJU_CMD_EPOCH	=	2,
	NFS_CUJU_CMD_COMMIT	=	3,
	NFS_CUJU_CMD_WRITE	=	4,
	NFS_CUJU_CMD_FAILOVER	=	5,
};

