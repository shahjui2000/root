/*****************************************************************************
 * Project: BaBar detector at the SLAC PEP-II B-factory
 * Package: RooFitTools
 *    File: $Id: RooFormula.rdl,v 1.8 2001/03/29 22:37:40 verkerke Exp $
 * Authors:
 *   WV, Wouter Verkerke, University of California Santa Barbara, verkerke@slac.stanford.edu
 * History:
 *   05-Mar-2001 WV Created initial version
 *
 * Copyright (C) 2001 University of California
 *****************************************************************************/
#ifndef ROO_FORMULA
#define ROO_FORMULA

#include "Rtypes.h"
#include "TFormula.h"
#include "TObjArray.h"
#include "RooFitCore/RooAbsReal.hh"
#include "RooFitCore/RooArgSet.hh"

class RooArgSet ;

class RooFormula : public TFormula {
public:
  // Constructors etc.
  RooFormula() ;
  RooFormula(const char* name, const char* formula, RooArgSet& varList);
  RooFormula(const char* name, const RooFormula& other) ;
  RooFormula(const RooFormula& other) ;
  RooFormula& operator=(RooFormula& other) ;
  virtual TObject* Clone() ;
  virtual ~RooFormula();
	
  // Dependent management
  RooArgSet& actualDependents() ;
  Bool_t changeDependents(RooArgSet& newDeps, Bool_t mustReplaceAll=kFALSE) ;

  // Function value accessor
  inline Bool_t ok() { return _isOK ; }
  Double_t eval() ;

  // Debugging
  void dump() ;
  Bool_t reCompile(const char* newFormula) ;

protected:
  
  void initCopy(const RooFormula& other) ;

  // Interface to TFormula engine
  Int_t DefinedVariable(TString &name) ;
  Double_t DefinedValue(Int_t code) ;

  Bool_t _isOK ;
  TList     _origList ;   //! Original list of dependents
  TObjArray _useList ;    //! List of actual dependents 
  TObjArray _labelList ;  //  List of label names for category objects  

  ClassDef(RooFormula,1) 
};

#endif
