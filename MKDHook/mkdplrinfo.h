#pragma once

struct char_info_entry {
	char* name;
	int file_table;
	int alt_file_table;
	char* scriptName;
};

struct mk_toc_entry {
	struct mk_file_entry* entry;
	int  previousSize;
	int  size;
};

struct mk_file_entry {
	char* name;
	struct mk_toc_entry* belong;
	int  type;
	int  unk;
};

struct select_screen_entry {
	int characterID;
	int soundID;
	char* headName;
	char* headLockedName;
	char* bodyName;
	char* bodyArchiveName;
	char* difficulty;
	char* style1;
	char* style2;
	char* style3;
};



extern struct char_info_entry pCharTable[];

void dump_char_table();

void set_char_table();
void calculate_custom_toc();