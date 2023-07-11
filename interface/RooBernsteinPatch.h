/*****************************************************************************
 * Project: RooFit                                                           *
 * Package: RooFitModels                                                     *
 *    File: $Id$
 * Authors:                                                                  *
 *   Kyle Cranmer
 *                                                                           *
 *                                                                           *
 * Redistribution and use in source and binary forms,                        *
 * with or without modification, are permitted according to the terms        *
 * listed in LICENSE (http://roofit.sourceforge.net/license.txt)             *
 *****************************************************************************/
#ifndef ROO_BERNSTEINPATCH
#define ROO_BERNSTEINPATCH
 
#include "RooAbsPdf.h"
#include "RooTemplateProxy.h"
#include "RooRealVar.h"
#include "RooListProxy.h"
#include "RooAbsRealLValue.h"
 
class RooRealVar;
class RooArgList ;
 
class RooBernsteinPatch : public RooAbsPdf {
public:
 
  RooBernsteinPatch() ;
  RooBernsteinPatch(const char *name, const char *title,
               RooAbsRealLValue& _x, const RooArgList& _coefList) ;
 
  RooBernsteinPatch(const RooBernsteinPatch& other, const char* name = 0);
  virtual TObject* clone(const char* newname) const { return new RooBernsteinPatch(*this, newname); }
  inline virtual ~RooBernsteinPatch() { }
 
  Int_t getAnalyticalIntegral(RooArgSet& allVars, RooArgSet& analVars, const char* rangeName=0) const ;
  Double_t analyticalIntegral(Int_t code, const char* rangeName=0) const ;
  void selectNormalizationRange(const char* rangeName=0, Bool_t force=kFALSE) ;
 
private:
  
  RooTemplateProxy<RooAbsRealLValue> _x ;
  RooListProxy _coefList ;
  std::string _refRangeName ;
 
  Double_t evaluate() const;
  RooSpan<double> evaluateBatch(std::size_t begin, std::size_t batchSize) const;
 
  Double_t _xmin;
  Double_t _xmax;
 
  ClassDef(RooBernsteinPatch,2) // Bernstein polynomial PDF
};
 
#endif