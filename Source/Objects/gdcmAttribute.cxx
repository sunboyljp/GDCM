#include "gdcmAttribute.h"
#include "gdcmAttributeFactory.h"
#include "gdcmVM.h"
#include "gdcmVR.h"
#include <string.h>

namespace gdcm
{

Attribute::Attribute()
{
  VRField = VR::VR_END;
  VMField = VM::VM_END;
}

Attribute::~Attribute()
{
}

void Attribute::SetVR(VR::VRType vr)
{
  VRField = vr;
}

void Attribute::SetVM(VM::VMType vm)
{
  VMField = vm;
}

void Attribute::SetLength(int len)
{
  switch(VRField)
    {
  case VR::UL:
      AF_UL.SetLength(len);
    break;
    }
}

void Attribute::Read(std::istream &_is)
{
  switch(VRField)
    {
  case VR::UL:
      AF_UL.Read(_is);
    break;
    }
}

//void Attribute::SetValue(const char *val)
//{
//  size_t len = strlen(val);
//  if( len )
//    {
//    char *value = new char[len+1];
//    memcpy(value, val, len);
//    delete[] Value;
//    Value = value;
//    Value[len] = '\0';
//    }
//  else
//    {
//    delete[] Value;
//    Value = 0;
//    }
//}
void Attribute::Print(std::ostream &_os) const
{
  switch(VRField)
    {
  case VR::UL:
      AF_UL.Print(_os);
    break;
    }
}

}
