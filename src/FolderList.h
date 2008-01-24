#ifndef FOLDERLIST_H
#define FOLDERLIST_H 1

/***************************************************************************

 YAM - Yet Another Folderer
 Copyright (C) 1995-2000 by Marcel Beck <mbeck@yam.ch>
 Copyright (C) 2000-2008 by YAM Open Source Team

 This program is free software; you can redistribute it and/or modify
 it under the terms of the GNU General Public License as published by
 the Free Software Foundation; either version 2 of the License, or
 (at your option) any later version.

 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.

 You should have received a copy of the GNU General Public License
 along with this program; if not, write to the Free Software
 Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA

 YAM Official Support Site :  http://www.yam.ch
 YAM OpenSource project    :  http://sourceforge.net/projects/yamos/

 $Id$

***************************************************************************/

#include <exec/lists.h>
#include <exec/nodes.h>
#include <exec/types.h>

// forward declarations
struct SignalSemaphore;
struct Folder;

struct FolderList
{
  struct MinList list;
  struct SignalSemaphore *lockSemaphore;
  ULONG count;
};

struct FolderNode
{
  struct MinNode node;
  struct Folder *folder;
};

struct FolderList *CreateFolderList(void);
void DeleteFolderList(struct FolderList *flist);
struct FolderList *CloneFolderList(struct FolderList *flist);
struct FolderNode *AddNewFolderNode(struct FolderList *flist, struct Folder *folder);
void AddFolderNode(struct FolderList *flist, struct FolderNode *fnode);
void RemoveFolderNode(struct FolderList *flist, struct FolderNode *fnode);
void DeleteFolderNode(struct FolderNode *fnode);

// check if a folder list is empty
#define IsFolderListEmpty(flist)                  IsListEmpty((struct List *)(flist))

// iterate through the list, the list must *NOT* be modified!
#define ForEachFolderNode(flist, fnode)           for(fnode = (struct FolderNode *)(flist)->list.mlh_Head; fnode->node.mln_Succ != NULL; fnode = (struct FolderNode *)fnode->node.mln_Succ)

// same as above, but the list may be modified
#define ForEachFolderNodeSafe(flist, fnode, next) for(fnode = (struct FolderNode *)(flist)->list.mlh_Head; (next = (struct FolderNode *)fnode->node.mln_Succ) != NULL; fnode = next)

// navigate in the list
#define FirstFolderNode(flist)                    (struct FolderNode *)(flist)->list.mlh_Head
#define LastFolderNode(flist)                     (struct FolderNode *)(flist)->list.mlh_TailPred
#define NextFolderNode(fnode)                     (((fnode)->node.mln_Succ != NULL && (fnode)->node.mln_Succ->mln_Succ != NULL) ? (struct FolderNode *)(fnode)->node.mln_Succ : NULL)
#define PreviousFolderNode(fnode)                 (((fnode)->node.mln_Pred != NULL && (fnode)->node.mln_Pred->mln_Pred != NULL) ? (struct FolderNode *)(fnode)->node.mln_Pred : NULL)

// lock and unlock a folder list via its semaphore
#define LockFolderList(mlist)                     ObtainSemaphore((flist)->lockSemaphore)
#define UnlockFolderList(mlist)                   ReleaseSemaphore((flist)->lockSemaphore)

#endif /* FOLDERLIST_H */

