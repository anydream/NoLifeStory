//////////////////////////////////////////////////////////////////////////////
// NoLifeClient - Part of the NoLifeStory project                           //
// Copyright (C) 2013 Peter Atashian                                        //
//                                                                          //
// This program is free software: you can redistribute it and/or modify     //
// it under the terms of the GNU Affero General Public License as           //
// published by the Free Software Foundation, either version 3 of the       //
// License, or (at your option) any later version.                          //
//                                                                          //
// This program is distributed in the hope that it will be useful,          //
// but WITHOUT ANY WARRANTY; without even the implied warranty of           //
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the            //
// GNU Affero General Public License for more details.                      //
//                                                                          //
// You should have received a copy of the GNU Affero General Public License //
// along with this program.  If not, see <http://www.gnu.org/licenses/>.    //
//////////////////////////////////////////////////////////////////////////////
#include "NoLifeClient.hpp"
namespace NL {
    namespace Log {
        ofstream LogFile("NoLifeClient.log");
        void Write(string s) {
            LogFile << s << endl;
        }
        void Wrap(function<void(void)> f) {
            try {
                f();
            } catch (string const & s) {
#ifdef NL_WINDOWS
                MessageBoxA(nullptr, s.c_str(), "ERROR", MB_OK);
#endif
                Log::Write("ERROR: " + s);
                Log::Write("ERROR: Aborting");
            } catch (char const * s) {
#ifdef NL_WINDOWS
                MessageBoxA(nullptr, s, "ERROR", MB_OK);
#endif
                Log::Write("ERROR: " + string(s));
                Log::Write("ERROR: Aborting");
            } catch (...) {
#ifdef NL_WINDOWS
                MessageBoxA(nullptr, "Unknown exception!", "ERROR", MB_OK);
#endif
                Log::Write("ERROR: Unknown exception");
                Log::Write("ERROR: Aborting");
            }
        }
    }
}