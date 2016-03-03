/*****************************************************************/
/*    NAME: Michael Benjamin, Henrik Schmidt, and John Leonard   */
/*    ORGN: Dept of Mechanical Eng / CSAIL, MIT Cambridge MA     */
/*    FILE: LogUtils.h                                           */
/*    DATE: August 7th, 2008                                     */
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

#ifndef LOG_UTILS_HEADER
#define LOG_UTILS_HEADER

#include <vector>
#include <string>
#include "ALogEntry.h"

std::string getTimeStamp(const std::string& line);
std::string getVarName(const std::string& line);
std::string getSourceName(const std::string& line);
std::string getSourceNameNoAux(const std::string& line);
std::string getDataEntry(const std::string& line);

std::string getNextRawLine(FILE*);
ALogEntry   getNextRawALogEntry(FILE*, bool allstrings=false);


void   stripInsigDigits(std::string& line);
void   shiftTimeStamp(std::string& line, double logstart);
double getLogStart(const std::string& line);
double getLogStartFromFile(const std::string& filename);
void   addVectorKey(std::vector<std::string>&, 
		    std::vector<bool>&, std::string);

double getEpochSecsFromTimeOfDay(std::string, int format=0);
double getEpochSecsFromTimeOfDay(double hour, double min, double sec);
double getEpochSecsFromDayOfYear(std::string, int format=0);
double getEpochSecsFromDayOfYear(double day, double month, double year);

#endif 

