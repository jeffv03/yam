#ifndef GENESIS_INTERFACE_DEF_H
#define GENESIS_INTERFACE_DEF_H

/*
** This file was machine generated by idltool 50.10.
** Do not edit
*/ 

#ifndef EXEC_TYPES_H
#include <exec/types.h>
#endif
#ifndef EXEC_EXEC_H
#include <exec/exec.h>
#endif
#ifndef EXEC_INTERFACES_H
#include <exec/interfaces.h>
#endif

#ifndef LIBRARIES_GENESIS_H
#include <libraries/genesis.h>
#endif

struct GenesisIFace
{
  struct InterfaceData Data;

  ULONG APICALL (*Obtain)(struct GenesisIFace *Self);
  ULONG APICALL (*Release)(struct GenesisIFace *Self);
  void APICALL (*Expunge)(struct GenesisIFace *Self);
  struct Interface * APICALL (*Clone)(struct GenesisIFace *Self);
  LONG APICALL (*GetFileSize)(struct GenesisIFace *Self, STRPTR last);
  BOOL APICALL (*ParseConfig)(struct GenesisIFace *Self, STRPTR par1, struct ParseConfig_Data * last);
  BOOL APICALL (*ParseNext)(struct GenesisIFace *Self, struct ParseConfig_Data * last);
  BOOL APICALL (*ParseNextLine)(struct GenesisIFace *Self, struct ParseConfig_Data * last);
  VOID APICALL (*ParseEnd)(struct GenesisIFace *Self, struct ParseConfig_Data * last);
  STRPTR APICALL (*ReallocCopy)(struct GenesisIFace *Self, STRPTR * par1, STRPTR last);
  VOID APICALL (*FreeUser)(struct GenesisIFace *Self, struct genUser * last);
  BOOL APICALL (*GetUserName)(struct GenesisIFace *Self, LONG par1, char * par2, LONG last);
  struct genUser * APICALL (*GetUser)(struct GenesisIFace *Self, STRPTR par1, STRPTR par2, STRPTR par3, LONG last);
  struct genUser * APICALL (*GetGlobalUser)(struct GenesisIFace *Self);
  VOID APICALL (*SetGlobalUser)(struct GenesisIFace *Self, struct genUser * last);
  VOID APICALL (*ClearUserList)(struct GenesisIFace *Self);
  BOOL APICALL (*ReloadUserList)(struct GenesisIFace *Self);
  LONG APICALL (*ReadFile)(struct GenesisIFace *Self, STRPTR par1, STRPTR par2, LONG last);
  BOOL APICALL (*WriteFile)(struct GenesisIFace *Self, STRPTR par1, STRPTR par2, LONG last);
  BOOL APICALL (*IsOnline)(struct GenesisIFace *Self, LONG last);
};

#endif /* GENESIS_INTERFACE_DEF_H */
