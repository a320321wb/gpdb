/*-------------------------------------------------------------------------
 *
 * typecmds.h
 *	  prototypes for typecmds.c.
 *
 *
 * Portions Copyright (c) 1996-2008, PostgreSQL Global Development Group
 * Portions Copyright (c) 1994, Regents of the University of California
 *
 * $PostgreSQL: pgsql/src/include/commands/typecmds.h,v 1.17 2007/01/05 22:19:54 momjian Exp $
 *
 *-------------------------------------------------------------------------
 */
#ifndef TYPECMDS_H
#define TYPECMDS_H

#include "nodes/parsenodes.h"


#define DEFAULT_TYPDELIM		','

extern void DefineType(List *names, List *parameters, Oid newOid, Oid newArrayOid);
extern void RemoveType(List *names, DropBehavior behavior, bool missing_ok);
extern void RemoveTypeById(Oid typeOid);
extern void DefineDomain(CreateDomainStmt *stmt);
extern void RemoveDomain(List *names, DropBehavior behavior, bool missing_ok);
extern Oid	DefineCompositeType(const RangeVar *typevar, List *coldeflist, Oid relOid, Oid comptypeOid);

extern void AlterDomainDefault(List *names, Node *defaultRaw);
extern void AlterDomainNotNull(List *names, bool notNull);
extern void AlterDomainAddConstraint(List *names, Node *constr);
extern void AlterDomainDropConstraint(List *names, const char *constrName,
						  DropBehavior behavior);

extern List *GetDomainConstraints(Oid typeOid);

extern void AlterTypeOwner(List *names, Oid newOwnerId);
extern void AlterTypeOwnerInternal(Oid typeOid, Oid newOwnerId,
								   bool hasDependEntry);
extern void AlterTypeNamespace(List *names, const char *newschema);
extern void AlterTypeNamespaceInternal(Oid typeOid, Oid nspOid,
									   bool isImplicitArray,
									   bool errorOnTableType);
extern void AlterType(AlterTypeStmt *stmt);
extern void AlterType(AlterTypeStmt *stmt);

#endif   /* TYPECMDS_H */
