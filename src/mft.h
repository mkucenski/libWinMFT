// Copyright 2017 Matthew A. Kucenski
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#ifndef _MFT_H_
#define _MFT_H_

#include "misc/windowsTypes.h"
#include "misc/coded-message.h"

// https://flatcap.org/linux-ntfs/ntfs/concepts/file_record.html
typedef struct _MFT_FILE_RECORD_HEADER {
	DWORD			vMagicNum;				// 0x00:	4649 4c45				FILE
	WORD			posUSN;					// 0x04:	
	WORD			cUSNLen;					// 0x06:	
	DWORDLONG	idLSN;					// 0x08:
	WORD			iSeqNum;					// 0x10:
	WORD			cHardLinks;				// 0x12:
	WORD			posFirstAttr;			// 0x14:
	WORD			fxFlags;					// 0x16:
	DWORD			cRecSize;				// 0x18:
	DWORD			cAllocRecSize;			// 0x1c:
	DWORDLONG	idBaseFILERec;			// 0x20:
	WORD			idNextAttr;				// 0x28:
} __attribute__((packed)) MFT_FILE_RECORD_HEADER;
#define MFT_FILE_RECORD_HEADER_LENGTH 	XXX
#define MFT_FILE_RECORD_MAGIC_NUMBER	0x46494c45	// "FILE"
#define MFT_FILE_RECORD_END_MARKER 		0xFFFFFFFF

// https://flatcap.org/linux-ntfs/ntfs/concepts/attribute_header.html
typedef struct _MFT_STD_RES_ATTR_HEADER {
	DWORD			vType;					// 0x00:
	DWORD			cLength;					// 0x04:
	BYTE			fResident;				// 0x08:
	BYTE			cNameLen;				// 0x09:
	WORD			posName;					// 0x0a:
	WORD			fxFlags;					// 0x0c:
	WORD			idAttr;					// 0x0e:
	DWORD			cAttrLen;				// 0x10:
	WORD			posAttr;					// 0x14:
	BYTE			fIndexed;				// 0x16:
	BYTE			zPadding;				// 0x17:
	// Attribute name/data...			// 0x18:
} __attribute__((packed)) MFT_STD_RES_ATTR_HEADER;
#define MFT_STD_RES_ATTR_HEADER_LENGTH	XXX

typedef struct _MFT_STD_NONRES_ATTR_HEADER {
	DWORD			vType;					// 0x00:
	DWORD			cLength;					// 0x04:
	BYTE			fResident;				// 0x08:
	BYTE			cNameLen;				// 0x09:
	WORD			posName;					// 0x0a:
	WORD			fxFlags;					// 0x0c:
	WORD			idAttr;					// 0x0e:
	DWORDLONG	idStartVCN;				// 0x10:
	DWORDLONG	idLastVCN;				// 0x18:
	WORD			posDataRuns;			// 0x20:
	WORD			cCompressionUnitSize;// 0x22:
	DWORD			zPadding;				// 0x24:
	DWORDLONG	cAllocAttrSize;		// 0x28:
	DWORDLONG	cAttrSize;				// 0x30:
	DWORDLONG	cCompressedDataSize;	// 0x38:
	// Attribute name/data runs...	// 0x40:
} __attribute__((packed)) MFT_STD_NONRES_ATTR_HEADER;
#define MFT_STD_NONRES_ATTR_HEADER_LEN	XXX

#endif // _MFT_H_

