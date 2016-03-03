/*****************************************************************/
/*    NAME: Michael Benjamin, Henrik Schmidt, and John Leonard   */
/*    ORGN: Dept of Mechanical Eng / CSAIL, MIT Cambridge MA     */
/*    FILE: LauncherULI.h                                        */
/*    DATE: Sep2511                                              */
/*                                                               */
/* This program is free software; you can redistribute it and/or */
/* modify it under the terms of the GNU General Public License   */
/* as published by the Free Software Foundation; either version  */
/* 2 of the License, or (at your option) any later version.      */
/*                                                               */
/* This program is distributed in the hope that it will be       */
/* useful, but WITHOUT ANY WARRANTY; without even the implied    */
/* warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR       */
/* PURPOSE. See the GNU General Public License for more details. */
/*                                                               */
/* You should have received a copy of the GNU General Public     */
/* License along with this program; if not, write to the Free    */
/* Software Foundation, Inc., 59 Temple Place - Suite 330,       */
/* Boston, MA 02111-1307, USA.                                   */
/*****************************************************************/

#ifndef ULOGVIEW_IPF_LAUNCHER
#define ULOGVIEW_IPF_LAUNCHER

#include <vector>
#include "ALogEntry.h"
#include "ULI_GUI.h"
#include "IvPDomain.h"
#include "IPF_TPlot.h"
#include "IterTPlot.h"
#include "GeneralLauncher.h"

class LauncherULI : public GeneralLauncher
{
 public:
  LauncherULI();
  virtual ~LauncherULI() {};
  
  ULI_GUI *launch(int argc, char **argv);

  std::string  getVName() {return(m_vname);};

protected:
  void setSizeOfGUI(int argc, char **argv);
  bool parseALogFile();

  bool buildPlotsAndGUI();
  

private:
  // geometry specifications for the viewer
  double  m_gui_height;
  double  m_gui_width;

  // Intermediate semi-raw data from the alog files
  // Outer vector index - one per vehicle, i.e., alog file.
  std::vector<ALogEntry>   m_entries_ipf_plot;

  IvPDomain   m_ivp_domain;

  std::string m_vname;
  std::string m_vname_bymoosdb;
  std::string m_vname_bynoderep;;

  ULI_GUI *m_gui;
  std::string m_window_layout;
};

#endif 

