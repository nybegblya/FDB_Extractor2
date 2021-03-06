#pragma once

#include "FDBFieldDef.h"

class FDBFieldManager
{
	public:

#pragma pack(1)
		struct s_file_header
		{
			const char description[128];
			DWORD unknown; // == 0x00006396

			DWORD entry_count;
			DWORD entry_size;
		};
#pragma pack()

		enum { E_NOT_INIT, E_LOADED, E_CHANGED, E_WRITTEN } state;

	public:
		FDBFieldManager();
		~FDBFieldManager();

		field_list* GetFieldDefinition(const FDBPackage::file_info& s_info, BYTE* data );

	private:

		void Load();
		void LoadCSV();
		void WriteCSV();

		field_def_list cache;

		field_def_list::iterator FindEntry(const std::string& name);
		FDBFieldDef AnalyseFile(const FDBPackage::file_info& s_info, BYTE* data);
		void Merge(FDBFieldDef& current, const FDBFieldDef& old_def);
};


extern FDBFieldManager g_field_manager;