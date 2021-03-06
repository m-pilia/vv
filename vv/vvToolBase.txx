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
===========================================================================**/

//------------------------------------------------------------------------------
template<class ToolType>
vvToolBase<ToolType>::vvToolBase(vvMainWindowBase * m)
{
  mMainWindowBase = m;
}
//------------------------------------------------------------------------------


//------------------------------------------------------------------------------
// Default value (to be overwritten)
template<class ToolType>
void vvToolBase<ToolType>::Initialize()
{
  SetToolName("Unnamed tool (use SetToolName in Initialize())");
  SetToolMenuName("Unnamed tool");
  SetToolIconFilename("");
  SetToolTip("Unamed tool.");
}
//------------------------------------------------------------------------------

