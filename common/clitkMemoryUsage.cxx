/*=========================================================================
  Program:   vv                     http://www.creatis.insa-lyon.fr/rio/vv

  Authors belong to: 
  - University of LYON              http://www.universite-lyon.fr/
  - Léon Bérard cancer center       http://oncora1.lyon.fnclcc.fr
  - CREATIS CNRS laboratory         http://www.creatis.insa-lyon.fr

  This software is distributed WITHOUT ANY WARRANTY; without even
  the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
  PURPOSE.  See the copyright notices for more information.

  It is distributed under dual licence

  - BSD        See included LICENSE.txt file
  - CeCILL-B   http://www.cecill.info/licences/Licence_CeCILL-B_V1-en.html
  ======================================================================-====*/

// clitk include
#include "clitkCommon.h"
#include "clitkMemoryUsage.h"

void clitk::PrintMemory(bool verbose, std::string s) 
{
#if CLITK_MEMORY_INFO == 1
  if (verbose) {
      //sleep(1); // wait to refresh memory ? need to let the system refresh the mem
      int * entries = new int;
      sg_process_stats * stat = new sg_process_stats;
      int i=0; 
      stat = sg_get_process_stats(entries);
      // Search the current pid in the list of processes
      while (stat[i].pid != getpid()) i++;
      // Display total memory size 
      if (s != "") std::cout << "==> " << s << ": ";
      static int previous=0;
      int mem = stat[i].proc_size/1000/1000; // in Mb
      std::cout << mem << "Mb (" << mem-previous << "Mb)" << std::endl;
      previous = mem;
      //DD(stat[i].proc_resident/1000/1000);
      //DD(stat[i].pid);
    }
#endif
  }

