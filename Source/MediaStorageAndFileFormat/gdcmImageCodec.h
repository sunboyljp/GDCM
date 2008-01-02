/*=========================================================================

  Program: GDCM (Grass Root DICOM). A DICOM library
  Module:  $URL$

  Copyright (c) 2006-2007 Mathieu Malaterre
  All rights reserved.
  See Copyright.txt or http://gdcm.sourceforge.net/Copyright.html for details.

     This software is distributed WITHOUT ANY WARRANTY; without even
     the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
     PURPOSE.  See the above copyright notice for more information.

=========================================================================*/
#ifndef __gdcmImageCodec_h
#define __gdcmImageCodec_h

#include "gdcmCodec.h"
#include "gdcmPhotometricInterpretation.h"
#include "gdcmLookupTable.h"
#include "gdcmSmartPointer.h"
#include "gdcmPixelType.h"

namespace gdcm
{
  
/*
 * \brief ImageCodec
 * \note Main codec, this is a central place for all implementation
 */
class ImageCodec : public Codec
{
public:
  ImageCodec();
  ~ImageCodec();
  bool CanDecode(TransferSyntax const &) { return false; }
  bool Decode(std::istream &is, std::ostream &os);

  unsigned int GetPlanarConfiguration() const
    {
    return PlanarConfiguration;
    }
  void SetPlanarConfiguration(unsigned int pc)
    {
    PlanarConfiguration = pc;
    }

  const PixelType &GetPixelType() const
    {
    return PT;
    }
  virtual void SetPixelType(PixelType const &pt)
    {
    PT = pt;
    }
  const PhotometricInterpretation &GetPhotometricInterpretation() const;
  void SetPhotometricInterpretation(PhotometricInterpretation const &pi);

  bool GetNeedByteSwap() const
    {
    return NeedByteSwap;
    }
  void SetNeedByteSwap(bool b)
    {
    NeedByteSwap = b;
    }
  void SetLUT(LookupTable const &lut)
    {
    LUT = SmartPointer<LookupTable>( const_cast<LookupTable*>(&lut) );
    }
  const LookupTable &GetLUT() const
    {
    return *LUT;
    }

protected:
  bool RequestPlanarConfiguration;
  bool RequestPaddedCompositePixelCode;
private:
  unsigned int PlanarConfiguration;
  PhotometricInterpretation PI;
  PixelType PT;
  bool NeedByteSwap;

  typedef SmartPointer<LookupTable> LUTPtr;
  LUTPtr LUT;

  bool DoPixelType(std::istream &is, std::ostream &os);
  bool DoByteSwap(std::istream &is, std::ostream &os);
  bool DoYBR(std::istream &is, std::ostream &os);
  bool DoPlanarConfiguration(std::istream &is, std::ostream &os);
  bool DoSimpleCopy(std::istream &is, std::ostream &os);
  bool DoPaddedCompositePixelCode(std::istream &is, std::ostream &os);
  bool DoInvertMonochrome(std::istream &is, std::ostream &os);
};

} // end namespace gdcm

#endif //__gdcmImageCodec_h
