#ifndef CPROJECT_userFIELD_HH
#define CPROJECT_userFIELD_HH

#include "G4SystemOfUnits.hh"
#include "G4ElectricField.hh"
#include "G4UniformElectricField.hh"

class UserField : public G4ElectricField
{
  public: 
   UserField(G4double voltage, G4double rmin, G4double rmax);
   ~UserField();

   virtual void GetFieldValue(const G4double Point[4], G4double *pField) const;
  private:
   G4double fvoltage;
   G4double frmin;
   G4double frmax;
};

#endif //CPROJECT_userFIELD_HH