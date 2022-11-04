#pragma once

struct mk_toc_entry {
	struct mk_file_entry* entry;
	int  previousSize;
	int  size;
};

struct mk_file_entry {
	char* name;
	struct mk_toc_entry* belong;
	int  type;
};

