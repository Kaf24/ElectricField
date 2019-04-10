#include "UserField.hh"

UserField::UserField(G4double voltage, G4double rmin, G4double rmax)
{ 
 fvoltage=voltage;
 frmin=rmin;
 frmax=rmax;
} 

UserField::~UserField()
{
}

void UserField::GetFieldValue(const G4double Point[4], G4double *pField) const
{
// G4double rmin = 0.1 * mm;
// G4double rmax = 30. * mm;
// G4double Uvolt= 20. * volt;
 G4double radius=powf((powf(Point[0],2.)+powf(Point[1],2.)),0.5);
 G4double fieldMag = fvoltage/(radius*(std::log(frmin/frmax)));

 G4double fi=atan2(Point[1],Point[0]);
 G4ThreeVector RadField = G4ThreeVector(fieldMag*cos(fi),fieldMag*sin(fi),0.);

 pField[0]=0.;
 pField[1]=0.;
 pField[2]=0.;
 pField[3]=RadField.x();
 pField[4]=RadField.y();
 pField[5]=RadField.z();
}
