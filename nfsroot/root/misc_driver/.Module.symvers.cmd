cmd_/home/pablo/ISO_II/nfsroot/root/misc_driver/Module.symvers := sed 's/ko$$/o/' /home/pablo/ISO_II/nfsroot/root/misc_driver/modules.order | scripts/mod/modpost -m -a   -o /home/pablo/ISO_II/nfsroot/root/misc_driver/Module.symvers -e -i Module.symvers   -T -