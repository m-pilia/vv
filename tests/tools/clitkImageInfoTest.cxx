/*=========================================================================
  Program:   vv                     http://www.creatis.insa-lyon.fr/rio/vv

  Authors belong to:
  - University of LYON              http://www.universite-lyon.fr/
  - Léon Bérard cancer center       http://www.centreleonberard.fr
  - CREATIS CNRS laboratory         http://www.creatis.insa-lyon.fr

  This software is distributed WITHOUT ANY WARRANTY; without even
  the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
  PURPOSE.  See the copyright notices for more information.

  It is distributed under dual licence

  - BSD        See included LICENSE.txt file
  - CeCILL-B   http://www.cecill.info/licences/Licence_CeCILL-B_V1-en.html
===========================================================================*/
#include <cstdlib>
#include <cstdio>

#include <iostream>
#include <sstream>
#include <string>

#include <itksys/SystemTools.hxx>


const size_t NUMTESTS=2;

// test files
const char mhd_files[NUMTESTS][128] = {
  CLITK_DATA_PATH"/4d/mhd/00.mhd",
  CLITK_DATA_PATH"/4d/mhd/bh.mhd"
};

// pre-written validation files. the idea
// is that the output generated from the test
// files match the verification files
const char validation_files[NUMTESTS][128] = {
  CLITK_DATA_PATH"/tools/clitkImageInfoTestValidate3D.out",
  CLITK_DATA_PATH"/tools/clitkImageInfoTestValidate4D.out"
};

int main(int argc, char** argv)
{
  system("pwd");
  
  bool failed = false;
  for (size_t i = 0; i < NUMTESTS; i++) {
    std::ostringstream cmd_line;
    cmd_line << "clitkImageInfo " << mhd_files[i] << " > clitkImageInfoTest.out";

    std::cout << "Executing " << cmd_line.str() << std::endl;
    system(cmd_line.str().c_str());
    
    // compare output with validation file
    std::cout << "Validating output against " << validation_files[i] << std::endl;
    bool differ = itksys::SystemTools::FilesDiffer("clitkImageInfoTest.out", validation_files[i]);
    if (differ)
    {
      failed = true;
      std::cout << "FAILED: Program output and reference do not match." << std::endl;
    }
    else
    {
      itksys::SystemTools::RemoveFile("clitkImageInfoTest.out");
      std::cout << "PASSED" << std::endl;
    }
  }
  return failed ? -1 : 0;
}