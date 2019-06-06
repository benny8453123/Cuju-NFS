/* For Cuju :
 * It's for kvm to use nfs cuju function
 * this file should include to Cuju/x86/kvm_main.c
 */

extern int nfs_cuju_cmd_send(unsigned int,int);
extern int nfs_cuju_cmd_send2(void *,int);
extern void *global_filp;
