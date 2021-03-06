/**************************************************************
 * 
 * Licensed to the Apache Software Foundation (ASF) under one
 * or more contributor license agreements.  See the NOTICE file
 * distributed with this work for additional information
 * regarding copyright ownership.  The ASF licenses this file
 * to you under the Apache License, Version 2.0 (the
 * "License"); you may not use this file except in compliance
 * with the License.  You may obtain a copy of the License at
 * 
 *   http://www.apache.org/licenses/LICENSE-2.0
 * 
 * Unless required by applicable law or agreed to in writing,
 * software distributed under the License is distributed on an
 * "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
 * KIND, either express or implied.  See the License for the
 * specific language governing permissions and limitations
 * under the License.
 * 
 *************************************************************/



#ifndef _PAMTYP_HXX
#define _PAMTYP_HXX

#include <svtools/txtcmp.hxx>
#include <pam.hxx>
#include <node.hxx>
#include <tools/string.hxx>

class SwpHints;
struct SwPosition;
class SwPaM;
class SwTxtAttr;

// Funktions-Deklarationen fuer die Move/Find-Methoden vom SwPaM

void GoStartDoc( SwPosition*);
void GoEndDoc( SwPosition*);
void GoStartSection( SwPosition*);
void GoEndSection( SwPosition*);
sal_Bool GoInDoc( SwPaM&, SwMoveFn);
sal_Bool GoInSection( SwPaM&, SwMoveFn);
sal_Bool GoInNode( SwPaM&, SwMoveFn);
sal_Bool GoInCntnt( SwPaM&, SwMoveFn);
sal_Bool GoInCntntCells( SwPaM&, SwMoveFn);
sal_Bool GoInCntntSkipHidden( SwPaM&, SwMoveFn);
sal_Bool GoInCntntCellsSkipHidden( SwPaM&, SwMoveFn);
const SwTxtAttr* GetFrwrdTxtHint( const SwpHints&, sal_uInt16&, xub_StrLen );
const SwTxtAttr* GetBkwrdTxtHint( const SwpHints&, sal_uInt16&, xub_StrLen );

sal_Bool GoNext(SwNode* pNd, SwIndex * pIdx, sal_uInt16 nMode );
sal_Bool GoPrevious(SwNode* pNd, SwIndex * pIdx, sal_uInt16 nMode );
SW_DLLPUBLIC SwCntntNode* GoNextNds( SwNodeIndex * pIdx, sal_Bool );
SwCntntNode* GoPreviousNds( SwNodeIndex * pIdx, sal_Bool );

// --------- Funktionsdefinitionen fuer die SwCrsrShell --------------

sal_Bool GoPrevPara( SwPaM&, SwPosPara);
sal_Bool GoCurrPara( SwPaM&, SwPosPara);
sal_Bool GoNextPara( SwPaM&, SwPosPara);
sal_Bool GoPrevSection( SwPaM&, SwPosSection);
sal_Bool GoCurrSection( SwPaM&, SwPosSection);
sal_Bool GoNextSection( SwPaM&, SwPosSection);


// ------------ Typedefiniton fuer Funktionen ----------------------

typedef sal_Bool (*GoNd)( SwNode*, SwIndex*, sal_uInt16 );
typedef SwCntntNode* (*GoNds)( SwNodeIndex*, sal_Bool );
typedef void (*GoDoc)( SwPosition* );
typedef void (*GoSection)( SwPosition* );
typedef sal_Bool (SwPosition:: *CmpOp)( const SwPosition& ) const;
typedef const SwTxtAttr* (*GetHint)( const SwpHints&, sal_uInt16&, xub_StrLen );
typedef int (utl::TextSearch:: *SearchTxt)( const String&, xub_StrLen*,
					xub_StrLen*, ::com::sun::star::util::SearchResult* );
typedef void (SwNodes:: *MvSection)( SwNodeIndex * ) const;


struct SwMoveFnCollection
{
	GoNd	  fnNd;
	GoNds	  fnNds;
	GoDoc	  fnDoc;
	GoSection fnSections;
	CmpOp	  fnCmpOp;
	GetHint   fnGetHint;
	SearchTxt fnSearch;
	MvSection fnSection;
};

// --------- Funktionsdefinitionen fuers Suchen --------------
SwCntntNode* GetNode( SwPaM&, sal_Bool&, SwMoveFn, sal_Bool bInReadOnly = sal_False );



#endif
