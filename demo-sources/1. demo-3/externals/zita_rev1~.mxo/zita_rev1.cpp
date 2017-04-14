//-----------------------------------------------------
//
// Code generated with Faust 0.9.71 (http://faust.grame.fr)
//-----------------------------------------------------
/* link with  */
#include <math.h>
#ifndef FAUSTPOWER
#define FAUSTPOWER
#include <cmath>
template <int N> inline float faustpower(float x)          { return powf(x,N); } 
template <int N> inline double faustpower(double x)        { return pow(x,N); }
template <int N> inline int faustpower(int x)              { return faustpower<N/2>(x) * faustpower<N-N/2>(x); } 
template <> 	 inline int faustpower<0>(int x)            { return 1; }
template <> 	 inline int faustpower<1>(int x)            { return x; }
#endif
/************************************************************************

	IMPORTANT NOTE : this file contains two clearly delimited sections :
	the ARCHITECTURE section (in two parts) and the USER section. Each section
	is governed by its own copyright and license. Please check individually
	each section for license and copyright information.
*************************************************************************/

/*******************BEGIN ARCHITECTURE SECTION (part 1/2)****************/

/************************************************************************
    FAUST Architecture File
	Copyright (C) 2004-2011 GRAME, Centre National de Creation Musicale
    ---------------------------------------------------------------------
    This Architecture section is free software; you can redistribute it
    and/or modify it under the terms of the GNU Lesser General Public
	License as published by the Free Software Foundation; either version 3
	of the License, or (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU Lesser General Public License for more details.

    You should have received a copy of the GNU Lesser General Public License
	along with this program; If not, see <http://www.gnu.org/licenses/>.

	EXCEPTION : As a special exception, you may create a larger work
	that contains this FAUST architecture section and distribute
	that work under terms of your choice, so long as this FAUST
	architecture section is not modified.

	MAX MSP SDK : in order to compile a MaxMSP external with this
	architecture file you will need the official MaxMSP SDK from
	cycling'74. Please check the corresponding license.

 ************************************************************************
 ************************************************************************/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <math.h>
#include <errno.h>
#include <time.h>
#include <unistd.h>
#include <fcntl.h>
#include <assert.h>
#include <string>
#include <vector>
#include <map>
#include <math.h>

#include <iostream>
#include <fstream>
#include <sstream>

#ifdef __APPLE__
#include <Carbon/Carbon.h>
#include <unistd.h>
#endif

#ifndef FAUST_UI_H
#define FAUST_UI_H

#ifndef FAUSTFLOAT
#define FAUSTFLOAT float
#endif

/*******************************************************************************
 * UI : Faust User Interface
 * This abstract class contains only the method that the faust compiler can
 * generate to describe a DSP interface.
 ******************************************************************************/

class UI
{

 public:

	UI() {}

	virtual ~UI() {}

    // -- widget's layouts

    virtual void openTabBox(const char* label) = 0;
    virtual void openHorizontalBox(const char* label) = 0;
    virtual void openVerticalBox(const char* label) = 0;
    virtual void closeBox() = 0;

    // -- active widgets

    virtual void addButton(const char* label, FAUSTFLOAT* zone) = 0;
    virtual void addCheckButton(const char* label, FAUSTFLOAT* zone) = 0;
    virtual void addVerticalSlider(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT min, FAUSTFLOAT max, FAUSTFLOAT step) = 0;
    virtual void addHorizontalSlider(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT min, FAUSTFLOAT max, FAUSTFLOAT step) = 0;
    virtual void addNumEntry(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT min, FAUSTFLOAT max, FAUSTFLOAT step) = 0;

    // -- passive widgets

    virtual void addHorizontalBargraph(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT min, FAUSTFLOAT max) = 0;
    virtual void addVerticalBargraph(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT min, FAUSTFLOAT max) = 0;

	// -- metadata declarations

    virtual void declare(FAUSTFLOAT*, const char*, const char*) {}
};

#endif
#ifndef FAUST_JSONUI_H
#define FAUST_JSONUI_H

#ifndef FAUSTFLOAT
#define FAUSTFLOAT float
#endif

#ifndef FAUST_PathUI_H
#define FAUST_PathUI_H

#include <vector>
#include <string>
#include <algorithm>

/*******************************************************************************
 * PathUI : Faust User Interface
 * Helper class to build complete path for items.
 ******************************************************************************/

class PathUI : public UI
{

    protected:
    
        std::vector<std::string> fControlsLevel;
       
    public:
    
        std::string buildPath(const std::string& label) 
        {
            std::string res = "/";
            for (size_t i = 0; i < fControlsLevel.size(); i++) {
                res += fControlsLevel[i];
                res += "/";
            }
            res += label;
            replace(res.begin(), res.end(), ' ', '_');
            return res;
        }
    
};

#endif
/************************************************************************
 ************************************************************************
    FAUST Architecture File
	Copyright (C) 2003-2011 GRAME, Centre National de Creation Musicale
    ---------------------------------------------------------------------
    This Architecture section is free software; you can redistribute it
    and/or modify it under the terms of the GNU General Public License
	as published by the Free Software Foundation; either version 3 of
	the License, or (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
	along with this program; If not, see <http://www.gnu.org/licenses/>.

 ************************************************************************
 ************************************************************************/
 
#ifndef __meta__
#define __meta__

struct Meta
{
    virtual void declare(const char* key, const char* value) = 0;
};

#endif


#include <vector>
#include <map>
#include <string>
#include <iostream>
#include <sstream>

#include <assert.h>

/*******************************************************************************
 * JSONUI : Faust User Interface
 * This class produce a complete JSON decription of the DSP instance.
 ******************************************************************************/

class JSONUI : public PathUI, public Meta
{

    protected:
    
        std::stringstream fJSON;
        std::stringstream fUI;
        std::stringstream fMeta;
        std::vector<std::pair <std::string, std::string> > fMetaAux;
        std::string fName;
    
        char fCloseUIPar;
        char fCloseMetaPar;
        int fTab;
    
        int fInputs, fOutputs;
         
        void tab(int n, std::ostream& fout)
        {
            fout << '\n';
            while (n-- > 0) {
                fout << '\t';
            }
        }
    
        void addMeta(int tab_val, bool quote = true)
        {
            if (fMetaAux.size() > 0) {
                tab(tab_val, fUI); fUI << "\"meta\": [";
                std::string sep = "";
                for (size_t i = 0; i < fMetaAux.size(); i++) {
                    fUI << sep;
                    tab(tab_val + 1, fUI); fUI << "{ \"" << fMetaAux[i].first << "\": \"" << fMetaAux[i].second << "\" }";
                    sep = ",";
                }
                tab(tab_val, fUI); fUI << ((quote) ? "],": "]");
                fMetaAux.clear();
            }
        }
        
        void init(const std::string& name, int inputs, int outputs)
        {
            fTab = 1;
            
            // Start Meta generation
            tab(fTab, fMeta); fMeta << "\"meta\": [";
            fCloseMetaPar = ' ';
            
            // Start UI generation
            tab(fTab, fUI); fUI << "\"ui\": [";
            fCloseUIPar = ' ';
            fTab += 1;
            
            fName = name;
            fInputs = inputs;
            fOutputs = outputs;
        }
      
     public:
     
        JSONUI(const std::string& name, int inputs, int outputs)
        {
            init(name, inputs, outputs);
        }

        JSONUI(int inputs, int outputs)
        {
            init("", inputs, outputs);
        }
 
        virtual ~JSONUI() {}

        // -- widget's layouts
    
        virtual void openGenericGroup(const char* label, const char* name)
        {
            fControlsLevel.push_back(label);
            fUI << fCloseUIPar;
            tab(fTab, fUI); fUI << "{";
            fTab += 1;
            tab(fTab, fUI); fUI << "\"type\": \"" << name << "\",";
            tab(fTab, fUI); fUI << "\"label\": \"" << label << "\",";
            addMeta(fTab + 1);
            tab(fTab, fUI); fUI << "\"items\": [";
            fCloseUIPar = ' ';
            fTab += 1;
        }

        virtual void openTabBox(const char* label)
        {
            openGenericGroup(label, "tgroup");
        }
    
        virtual void openHorizontalBox(const char* label)
        {
            openGenericGroup(label, "hgroup");
        }
    
        virtual void openVerticalBox(const char* label)
        {
            openGenericGroup(label, "vgroup");
        }
    
        virtual void closeBox()
        {
            fControlsLevel.pop_back();
            fTab -= 1;
            tab(fTab, fUI); fUI << "]";
            fTab -= 1;
            tab(fTab, fUI); fUI << "}";
            fCloseUIPar = ',';
        }
    
        // -- active widgets
    
        virtual void addGenericButton(const char* label, const char* name)
        {
            fUI << fCloseUIPar;
            tab(fTab, fUI); fUI << "{";
            tab(fTab + 1, fUI); fUI << "\"type\": \"" << name << "\",";
            tab(fTab + 1, fUI); fUI << "\"label\": \"" << label << "\"" << ",";
            tab(fTab + 1, fUI); fUI << "\"address\": \"" << buildPath(label) << "\"" << ((fMetaAux.size() > 0) ? "," : "");
            addMeta(fTab + 1, false);
            tab(fTab, fUI); fUI << "}";
            fCloseUIPar = ',';
        }

        virtual void addButton(const char* label, FAUSTFLOAT* zone)
        {
            addGenericButton(label, "button");
        }
    
        virtual void addCheckButton(const char* label, FAUSTFLOAT* zone)
        {
            addGenericButton(label, "checkbox");
        }

        virtual void addGenericEntry(const char* label, const char* name, FAUSTFLOAT init, FAUSTFLOAT min, FAUSTFLOAT max, FAUSTFLOAT step)
        {
            fUI << fCloseUIPar;
            tab(fTab, fUI); fUI << "{";
            tab(fTab + 1, fUI); fUI << "\"type\": \"" << name << "\",";
            tab(fTab + 1, fUI); fUI << "\"label\": \"" << label << "\"" << ",";
            tab(fTab + 1, fUI); fUI << "\"address\": \"" << buildPath(label) << "\"" << ",";
            addMeta(fTab + 1);
            tab(fTab + 1, fUI); fUI << "\"init\": \"" << init << "\",";
            tab(fTab + 1, fUI); fUI << "\"min\": \"" << min << "\",";
            tab(fTab + 1, fUI); fUI << "\"max\": \"" << max << "\",";
            tab(fTab + 1, fUI); fUI << "\"step\": \"" << step << "\"";
            tab(fTab, fUI); fUI << "}";
            fCloseUIPar = ',';
        }
    
        virtual void addVerticalSlider(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT min, FAUSTFLOAT max, FAUSTFLOAT step)
        {
            addGenericEntry(label, "vslider", init, min, max, step);
        }
    
        virtual void addHorizontalSlider(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT min, FAUSTFLOAT max, FAUSTFLOAT step)
        {
            addGenericEntry(label, "hslider", init, min, max, step);
        }
    
        virtual void addNumEntry(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT min, FAUSTFLOAT max, FAUSTFLOAT step)
        {
            addGenericEntry(label, "nentry", init, min, max, step);
        }

        // -- passive widgets
    
        virtual void addGenericBargraph(const char* label, const char* name, FAUSTFLOAT min, FAUSTFLOAT max) 
        {
            fUI << fCloseUIPar;
            tab(fTab, fUI); fUI << "{";
            tab(fTab + 1, fUI); fUI << "\"type\": \"" << name << "\",";
            tab(fTab + 1, fUI); fUI << "\"label\": \"" << label << "\"" << ",";
            tab(fTab + 1, fUI); fUI << "\"address\": \"" << buildPath(label) << "\"" << ",";
            addMeta(fTab + 1);
            tab(fTab + 1, fUI); fUI << "\"min\": \"" << min << "\",";
            tab(fTab + 1, fUI); fUI << "\"max\": \"" << max << "\"";
            tab(fTab, fUI); fUI << "}";
            fCloseUIPar = ',';
        }

        virtual void addHorizontalBargraph(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT min, FAUSTFLOAT max) 
        {
            addGenericBargraph(label, "hbargraph", min, max);
        }
    
        virtual void addVerticalBargraph(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT min, FAUSTFLOAT max)
        {
            addGenericBargraph(label, "vbargraph", min, max);
        }

        // -- metadata declarations

        virtual void declare(FAUSTFLOAT* zone, const char* key, const char* val)
        {
            fMetaAux.push_back(std::make_pair(key, val));
        }
    
        // Meta interface
        virtual void declare(const char* key, const char* value)
        {
            fMeta << fCloseMetaPar;
            if ((strcmp(key, "name") == 0) && (fName == "")) fName = value;
            tab(fTab, fMeta); fMeta << "{ " << "\"" << key << "\"" << ": " << "\"" << value << "\" }";
            fCloseMetaPar = ',';
        }
    
        inline std::string flatten(const std::string& src)
        {
            std::stringstream dst;
            for (size_t i = 0; i < src.size(); i++) {
                switch (src[i]) {
                    case '\n':
                    case '\t':
                        dst << ' ';
                        break;
                    case '"':
                        dst << "\\" << '"';
                        break;
                    default:
                        dst << src[i];
                        break;
                }
            }
            return dst.str();
        }
    
        std::string JSON(bool flat = false)
        {
            fTab = 0;
            fJSON << "{";
            fTab += 1;
            tab(fTab, fJSON); fJSON << "\"name\": \"" << fName << "\",";
            if (fInputs > 0) { tab(fTab, fJSON); fJSON << "\"inputs\": \"" << fInputs << "\","; }
            if (fOutputs > 0) { tab(fTab, fJSON); fJSON << "\"outputs\": \"" << fOutputs << "\","; }
            tab(fTab, fMeta); fMeta << "],";
            tab(fTab, fUI); fUI << "]";
            fTab -= 1;
            if (fCloseMetaPar == ',') { // If "declare" has been called, fCloseMetaPar state is now ','
                fJSON << fMeta.str() << fUI.str();
            } else {
                fJSON << fUI.str();
            }
            tab(fTab, fJSON); fJSON << "}" << std::endl;
            return (flat) ? flatten(fJSON.str()) : fJSON.str();
        }
    
};

#endif
/************************************************************************
	IMPORTANT NOTE : this file contains two clearly delimited sections :
	the ARCHITECTURE section (in two parts) and the USER section. Each section
	is governed by its own copyright and license. Please check individually
	each section for license and copyright information.
*************************************************************************/

/*******************BEGIN ARCHITECTURE SECTION (part 1/2)****************/

/************************************************************************
    FAUST Architecture File
	Copyright (C) 2003-2011 GRAME, Centre National de Creation Musicale
    ---------------------------------------------------------------------
    This Architecture section is free software; you can redistribute it
    and/or modify it under the terms of the GNU General Public License
	as published by the Free Software Foundation; either version 3 of
	the License, or (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
	along with this program; If not, see <http://www.gnu.org/licenses/>.

	EXCEPTION : As a special exception, you may create a larger work
	that contains this FAUST architecture section and distribute
	that work under terms of your choice, so long as this FAUST
	architecture section is not modified.


 ************************************************************************
 ************************************************************************/
 
/******************************************************************************
*******************************************************************************

								FAUST DSP

*******************************************************************************
*******************************************************************************/

#ifndef __dsp__
#define __dsp__

#ifndef FAUSTFLOAT
#define FAUSTFLOAT float
#endif

class UI;

//----------------------------------------------------------------
//  signal processor definition
//----------------------------------------------------------------

class dsp {
 protected:
	int fSamplingFreq;
 public:
	dsp() {}
	virtual ~dsp() {}

	virtual int getNumInputs() 										= 0;
	virtual int getNumOutputs() 									= 0;
	virtual void buildUserInterface(UI* ui_interface) 				= 0;
	virtual void init(int samplingRate) 							= 0;
 	virtual void compute(int len, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs) 	= 0;
};

// On Intel set FZ (Flush to Zero) and DAZ (Denormals Are Zero)
// flags to avoid costly denormals
#ifdef __SSE__
    #include <xmmintrin.h>
    #ifdef __SSE2__
        #define AVOIDDENORMALS _mm_setcsr(_mm_getcsr() | 0x8040)
    #else
        #define AVOIDDENORMALS _mm_setcsr(_mm_getcsr() | 0x8000)
    #endif
#else
    #define AVOIDDENORMALS
#endif

#endif
/************************************************************************
 ************************************************************************
    FAUST Architecture File
	Copyright (C) 2003-2011 GRAME, Centre National de Creation Musicale
    ---------------------------------------------------------------------
    This Architecture section is free software; you can redistribute it
    and/or modify it under the terms of the GNU General Public License
	as published by the Free Software Foundation; either version 3 of
	the License, or (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
	along with this program; If not, see <http://www.gnu.org/licenses/>.

 ************************************************************************
 ************************************************************************/
 
#ifndef __misc__
#define __misc__

#include <algorithm>
#include <map>
#include <string.h>
#include <stdlib.h>


using std::max;
using std::min;

struct XXXX_Meta : std::map<const char*, const char*>
{
    void declare(const char* key, const char* value) { (*this)[key]=value; }
};

struct MY_Meta : Meta, std::map<const char*, const char*>
{
    void declare(const char* key, const char* value) { (*this)[key]=value; }
};

inline int	lsr(int x, int n)	{ return int(((unsigned int)x) >> n); }
inline int 	int2pow2(int x)		{ int r=0; while ((1<<r)<x) r++; return r; }

long lopt(char *argv[], const char *name, long def)
{
	int	i;
	for (i = 0; argv[i]; i++) if (!strcmp(argv[i], name)) return atoi(argv[i+1]);
	return def;
}

bool isopt(char *argv[], const char *name)
{
	int	i;
	for (i = 0; argv[i]; i++) if (!strcmp(argv[i], name)) return true;
	return false;
}

const char* lopts(char *argv[], const char *name, const char* def)
{
	int	i;
	for (i = 0; argv[i]; i++) if (!strcmp(argv[i], name)) return argv[i+1];
	return def;
}
#endif


using namespace std;

/******************************************************************************
*******************************************************************************

							       VECTOR INTRINSICS

*******************************************************************************
*******************************************************************************/


/********************END ARCHITECTURE SECTION (part 1/2)****************/

/**************************BEGIN USER SECTION **************************/

#ifndef FAUSTFLOAT
#define FAUSTFLOAT float
#endif  


#ifndef FAUSTCLASS 
#define FAUSTCLASS mydsp
#endif

class mydsp : public dsp {
  private:
	FAUSTFLOAT 	fslider0;
	float 	fRec0[2];
	int 	IOTA;
	float 	fVec0[8192];
	FAUSTFLOAT 	fslider1;
	int 	iConst0;
	float 	fConst1;
	float 	fRec12[2];
	FAUSTFLOAT 	fslider2;
	float 	fConst2;
	float 	fConst3;
	FAUSTFLOAT 	fslider3;
	FAUSTFLOAT 	fslider4;
	float 	fConst4;
	float 	fRec11[2];
	float 	fVec1[8192];
	float 	fConst5;
	int 	iConst6;
	FAUSTFLOAT 	fslider5;
	float 	fConst7;
	float 	fVec2[2048];
	int 	iConst8;
	float 	fRec9[2];
	float 	fRec16[2];
	float 	fConst9;
	float 	fConst10;
	float 	fRec15[2];
	float 	fVec3[8192];
	float 	fConst11;
	int 	iConst12;
	float 	fVec4[1024];
	int 	iConst13;
	float 	fRec13[2];
	float 	fRec20[2];
	float 	fConst14;
	float 	fConst15;
	float 	fRec19[2];
	float 	fVec5[8192];
	float 	fConst16;
	int 	iConst17;
	float 	fVec6[2048];
	int 	iConst18;
	float 	fRec17[2];
	float 	fRec24[2];
	float 	fConst19;
	float 	fConst20;
	float 	fRec23[2];
	float 	fVec7[8192];
	float 	fConst21;
	int 	iConst22;
	float 	fVec8[1024];
	int 	iConst23;
	float 	fRec21[2];
	float 	fRec28[2];
	float 	fConst24;
	float 	fConst25;
	float 	fRec27[2];
	float 	fVec9[16384];
	float 	fConst26;
	int 	iConst27;
	float 	fVec10[8192];
	float 	fVec11[2048];
	int 	iConst28;
	float 	fRec25[2];
	float 	fRec32[2];
	float 	fConst29;
	float 	fConst30;
	float 	fRec31[2];
	float 	fVec12[8192];
	float 	fConst31;
	int 	iConst32;
	float 	fVec13[2048];
	int 	iConst33;
	float 	fRec29[2];
	float 	fRec36[2];
	float 	fConst34;
	float 	fConst35;
	float 	fRec35[2];
	float 	fVec14[16384];
	float 	fConst36;
	int 	iConst37;
	float 	fVec15[2048];
	int 	iConst38;
	float 	fRec33[2];
	float 	fRec40[2];
	float 	fConst39;
	float 	fConst40;
	float 	fRec39[2];
	float 	fVec16[16384];
	float 	fConst41;
	int 	iConst42;
	float 	fVec17[1024];
	int 	iConst43;
	float 	fRec37[2];
	float 	fRec1[3];
	float 	fRec2[3];
	float 	fRec3[3];
	float 	fRec4[3];
	float 	fRec5[3];
	float 	fRec6[3];
	float 	fRec7[3];
	float 	fRec8[3];
	FAUSTFLOAT 	fslider6;
	FAUSTFLOAT 	fslider7;
	float 	fConst44;
	float 	fRec41[3];
	FAUSTFLOAT 	fslider8;
	FAUSTFLOAT 	fslider9;
	float 	fRec42[3];
	FAUSTFLOAT 	fslider10;
	float 	fRec43[2];
	float 	fRec44[3];
	float 	fRec45[3];
  public:
	static void metadata(Meta* m) 	{ 
		m->declare("effect.lib/name", "Faust Audio Effect Library");
		m->declare("effect.lib/author", "Julius O. Smith (jos at ccrma.stanford.edu)");
		m->declare("effect.lib/copyright", "Julius O. Smith III");
		m->declare("effect.lib/version", "1.33");
		m->declare("effect.lib/license", "STK-4.3");
		m->declare("effect.lib/exciter_name", "Harmonic Exciter");
		m->declare("effect.lib/exciter_author", "Priyanka Shekar (pshekar@ccrma.stanford.edu)");
		m->declare("effect.lib/exciter_copyright", "Copyright (c) 2013 Priyanka Shekar");
		m->declare("effect.lib/exciter_version", "1.0");
		m->declare("effect.lib/exciter_license", "MIT License (MIT)");
		m->declare("filter.lib/name", "Faust Filter Library");
		m->declare("filter.lib/author", "Julius O. Smith (jos at ccrma.stanford.edu)");
		m->declare("filter.lib/copyright", "Julius O. Smith III");
		m->declare("filter.lib/version", "1.29");
		m->declare("filter.lib/license", "STK-4.3");
		m->declare("filter.lib/reference", "https://ccrma.stanford.edu/~jos/filters/");
		m->declare("music.lib/name", "Music Library");
		m->declare("music.lib/author", "GRAME");
		m->declare("music.lib/copyright", "GRAME");
		m->declare("music.lib/version", "1.0");
		m->declare("music.lib/license", "LGPL with exception");
		m->declare("math.lib/name", "Math Library");
		m->declare("math.lib/author", "GRAME");
		m->declare("math.lib/copyright", "GRAME");
		m->declare("math.lib/version", "1.0");
		m->declare("math.lib/license", "LGPL with exception");
	}

	virtual int getNumInputs() 	{ return 2; }
	virtual int getNumOutputs() 	{ return 2; }
	static void classInit(int samplingFreq) {
	}
	virtual void instanceInit(int samplingFreq) {
		fSamplingFreq = samplingFreq;
		fslider0 = 0.0f;
		for (int i=0; i<2; i++) fRec0[i] = 0;
		IOTA = 0;
		for (int i=0; i<8192; i++) fVec0[i] = 0;
		fslider1 = 2e+02f;
		iConst0 = min(192000, max(1, fSamplingFreq));
		fConst1 = (3.141592653589793f / float(iConst0));
		for (int i=0; i<2; i++) fRec12[i] = 0;
		fslider2 = 2.0f;
		fConst2 = floorf((0.5f + (0.174713f * iConst0)));
		fConst3 = ((0 - (6.907755278982138f * fConst2)) / float(iConst0));
		fslider3 = 3.0f;
		fslider4 = 6e+03f;
		fConst4 = (6.283185307179586f / float(iConst0));
		for (int i=0; i<2; i++) fRec11[i] = 0;
		for (int i=0; i<8192; i++) fVec1[i] = 0;
		fConst5 = floorf((0.5f + (0.022904f * iConst0)));
		iConst6 = int((int((fConst2 - fConst5)) & 8191));
		fslider5 = 6e+01f;
		fConst7 = (0.001f * iConst0);
		for (int i=0; i<2048; i++) fVec2[i] = 0;
		iConst8 = int((int((fConst5 - 1)) & 2047));
		for (int i=0; i<2; i++) fRec9[i] = 0;
		for (int i=0; i<2; i++) fRec16[i] = 0;
		fConst9 = floorf((0.5f + (0.153129f * iConst0)));
		fConst10 = ((0 - (6.907755278982138f * fConst9)) / float(iConst0));
		for (int i=0; i<2; i++) fRec15[i] = 0;
		for (int i=0; i<8192; i++) fVec3[i] = 0;
		fConst11 = floorf((0.5f + (0.020346f * iConst0)));
		iConst12 = int((int((fConst9 - fConst11)) & 8191));
		for (int i=0; i<1024; i++) fVec4[i] = 0;
		iConst13 = int((int((fConst11 - 1)) & 1023));
		for (int i=0; i<2; i++) fRec13[i] = 0;
		for (int i=0; i<2; i++) fRec20[i] = 0;
		fConst14 = floorf((0.5f + (0.127837f * iConst0)));
		fConst15 = ((0 - (6.907755278982138f * fConst14)) / float(iConst0));
		for (int i=0; i<2; i++) fRec19[i] = 0;
		for (int i=0; i<8192; i++) fVec5[i] = 0;
		fConst16 = floorf((0.5f + (0.031604f * iConst0)));
		iConst17 = int((int((fConst14 - fConst16)) & 8191));
		for (int i=0; i<2048; i++) fVec6[i] = 0;
		iConst18 = int((int((fConst16 - 1)) & 2047));
		for (int i=0; i<2; i++) fRec17[i] = 0;
		for (int i=0; i<2; i++) fRec24[i] = 0;
		fConst19 = floorf((0.5f + (0.125f * iConst0)));
		fConst20 = ((0 - (6.907755278982138f * fConst19)) / float(iConst0));
		for (int i=0; i<2; i++) fRec23[i] = 0;
		for (int i=0; i<8192; i++) fVec7[i] = 0;
		fConst21 = floorf((0.5f + (0.013458f * iConst0)));
		iConst22 = int((int((fConst19 - fConst21)) & 8191));
		for (int i=0; i<1024; i++) fVec8[i] = 0;
		iConst23 = int((int((fConst21 - 1)) & 1023));
		for (int i=0; i<2; i++) fRec21[i] = 0;
		for (int i=0; i<2; i++) fRec28[i] = 0;
		fConst24 = floorf((0.5f + (0.210389f * iConst0)));
		fConst25 = ((0 - (6.907755278982138f * fConst24)) / float(iConst0));
		for (int i=0; i<2; i++) fRec27[i] = 0;
		for (int i=0; i<16384; i++) fVec9[i] = 0;
		fConst26 = floorf((0.5f + (0.024421f * iConst0)));
		iConst27 = int((int((fConst24 - fConst26)) & 16383));
		for (int i=0; i<8192; i++) fVec10[i] = 0;
		for (int i=0; i<2048; i++) fVec11[i] = 0;
		iConst28 = int((int((fConst26 - 1)) & 2047));
		for (int i=0; i<2; i++) fRec25[i] = 0;
		for (int i=0; i<2; i++) fRec32[i] = 0;
		fConst29 = floorf((0.5f + (0.192303f * iConst0)));
		fConst30 = ((0 - (6.907755278982138f * fConst29)) / float(iConst0));
		for (int i=0; i<2; i++) fRec31[i] = 0;
		for (int i=0; i<8192; i++) fVec12[i] = 0;
		fConst31 = floorf((0.5f + (0.029291f * iConst0)));
		iConst32 = int((int((fConst29 - fConst31)) & 8191));
		for (int i=0; i<2048; i++) fVec13[i] = 0;
		iConst33 = int((int((fConst31 - 1)) & 2047));
		for (int i=0; i<2; i++) fRec29[i] = 0;
		for (int i=0; i<2; i++) fRec36[i] = 0;
		fConst34 = floorf((0.5f + (0.256891f * iConst0)));
		fConst35 = ((0 - (6.907755278982138f * fConst34)) / float(iConst0));
		for (int i=0; i<2; i++) fRec35[i] = 0;
		for (int i=0; i<16384; i++) fVec14[i] = 0;
		fConst36 = floorf((0.5f + (0.027333f * iConst0)));
		iConst37 = int((int((fConst34 - fConst36)) & 16383));
		for (int i=0; i<2048; i++) fVec15[i] = 0;
		iConst38 = int((int((fConst36 - 1)) & 2047));
		for (int i=0; i<2; i++) fRec33[i] = 0;
		for (int i=0; i<2; i++) fRec40[i] = 0;
		fConst39 = floorf((0.5f + (0.219991f * iConst0)));
		fConst40 = ((0 - (6.907755278982138f * fConst39)) / float(iConst0));
		for (int i=0; i<2; i++) fRec39[i] = 0;
		for (int i=0; i<16384; i++) fVec16[i] = 0;
		fConst41 = floorf((0.5f + (0.019123f * iConst0)));
		iConst42 = int((int((fConst39 - fConst41)) & 16383));
		for (int i=0; i<1024; i++) fVec17[i] = 0;
		iConst43 = int((int((fConst41 - 1)) & 1023));
		for (int i=0; i<2; i++) fRec37[i] = 0;
		for (int i=0; i<3; i++) fRec1[i] = 0;
		for (int i=0; i<3; i++) fRec2[i] = 0;
		for (int i=0; i<3; i++) fRec3[i] = 0;
		for (int i=0; i<3; i++) fRec4[i] = 0;
		for (int i=0; i<3; i++) fRec5[i] = 0;
		for (int i=0; i<3; i++) fRec6[i] = 0;
		for (int i=0; i<3; i++) fRec7[i] = 0;
		for (int i=0; i<3; i++) fRec8[i] = 0;
		fslider6 = 0.0f;
		fslider7 = 315.0f;
		fConst44 = (6.283185307179586f / float(iConst0));
		for (int i=0; i<3; i++) fRec41[i] = 0;
		fslider8 = 0.0f;
		fslider9 = 1.5e+03f;
		for (int i=0; i<3; i++) fRec42[i] = 0;
		fslider10 = -2e+01f;
		for (int i=0; i<2; i++) fRec43[i] = 0;
		for (int i=0; i<3; i++) fRec44[i] = 0;
		for (int i=0; i<3; i++) fRec45[i] = 0;
	}
	virtual void init(int samplingFreq) {
		classInit(samplingFreq);
		instanceInit(samplingFreq);
	}
	virtual void buildUserInterface(UI* interface) {
		interface->declare(0, "0", "");
		interface->declare(0, "tooltip", "~ ZITA REV1 FEEDBACK DELAY NETWORK (FDN) & SCHROEDER ALLPASS-COMB REVERBERATOR (8x8). See Faust's effect.lib for documentation and references");
		interface->openHorizontalBox("Zita_Rev1");
		interface->declare(0, "1", "");
		interface->openHorizontalBox("Input");
		interface->declare(&fslider5, "1", "");
		interface->declare(&fslider5, "style", "knob");
		interface->declare(&fslider5, "tooltip", "Delay in ms before reverberation begins");
		interface->declare(&fslider5, "unit", "ms");
		interface->addVerticalSlider("In Delay", &fslider5, 6e+01f, 2e+01f, 1e+02f, 1.0f);
		interface->closeBox();
		interface->declare(0, "2", "");
		interface->openHorizontalBox("Decay Times in Bands (see tooltips)");
		interface->declare(&fslider1, "1", "");
		interface->declare(&fslider1, "scale", "log");
		interface->declare(&fslider1, "style", "knob");
		interface->declare(&fslider1, "tooltip", "Crossover frequency (Hz) separating low and middle frequencies");
		interface->declare(&fslider1, "unit", "Hz");
		interface->addVerticalSlider("LF X", &fslider1, 2e+02f, 5e+01f, 1e+03f, 1.0f);
		interface->declare(&fslider3, "2", "");
		interface->declare(&fslider3, "scale", "log");
		interface->declare(&fslider3, "style", "knob");
		interface->declare(&fslider3, "tooltip", "T60 = time (in seconds) to decay 60dB in low-frequency band");
		interface->declare(&fslider3, "unit", "s");
		interface->addVerticalSlider("Low RT60", &fslider3, 3.0f, 1.0f, 8.0f, 0.1f);
		interface->declare(&fslider2, "3", "");
		interface->declare(&fslider2, "scale", "log");
		interface->declare(&fslider2, "style", "knob");
		interface->declare(&fslider2, "tooltip", "T60 = time (in seconds) to decay 60dB in middle band");
		interface->declare(&fslider2, "unit", "s");
		interface->addVerticalSlider("Mid RT60", &fslider2, 2.0f, 1.0f, 8.0f, 0.1f);
		interface->declare(&fslider4, "4", "");
		interface->declare(&fslider4, "scale", "log");
		interface->declare(&fslider4, "style", "knob");
		interface->declare(&fslider4, "tooltip", "Frequency (Hz) at which the high-frequency T60 is half the middle-band's T60");
		interface->declare(&fslider4, "unit", "Hz");
		interface->addVerticalSlider("HF Damping", &fslider4, 6e+03f, 1.5e+03f, 2.352e+04f, 1.0f);
		interface->closeBox();
		interface->declare(0, "3", "");
		interface->openHorizontalBox("RM Peaking Equalizer 1");
		interface->declare(&fslider7, "1", "");
		interface->declare(&fslider7, "scale", "log");
		interface->declare(&fslider7, "style", "knob");
		interface->declare(&fslider7, "tooltip", "Center-frequency of second-order Regalia-Mitra peaking equalizer section 1");
		interface->declare(&fslider7, "unit", "Hz");
		interface->addVerticalSlider("Eq1 Freq", &fslider7, 315.0f, 4e+01f, 2.5e+03f, 1.0f);
		interface->declare(&fslider6, "2", "");
		interface->declare(&fslider6, "style", "knob");
		interface->declare(&fslider6, "tooltip", "Peak level in dB of second-order Regalia-Mitra peaking equalizer section 1");
		interface->declare(&fslider6, "unit", "dB");
		interface->addVerticalSlider("Eq1 Level", &fslider6, 0.0f, -15.0f, 15.0f, 0.1f);
		interface->closeBox();
		interface->declare(0, "4", "");
		interface->openHorizontalBox("RM Peaking Equalizer 2");
		interface->declare(&fslider9, "1", "");
		interface->declare(&fslider9, "scale", "log");
		interface->declare(&fslider9, "style", "knob");
		interface->declare(&fslider9, "tooltip", "Center-frequency of second-order Regalia-Mitra peaking equalizer section 2");
		interface->declare(&fslider9, "unit", "Hz");
		interface->addVerticalSlider("Eq2 Freq", &fslider9, 1.5e+03f, 1.6e+02f, 1e+04f, 1.0f);
		interface->declare(&fslider8, "2", "");
		interface->declare(&fslider8, "style", "knob");
		interface->declare(&fslider8, "tooltip", "Peak level in dB of second-order Regalia-Mitra peaking equalizer section 2");
		interface->declare(&fslider8, "unit", "dB");
		interface->addVerticalSlider("Eq2 Level", &fslider8, 0.0f, -15.0f, 15.0f, 0.1f);
		interface->closeBox();
		interface->declare(0, "5", "");
		interface->openHorizontalBox("Output");
		interface->declare(&fslider0, "1", "");
		interface->declare(&fslider0, "style", "knob");
		interface->declare(&fslider0, "tooltip", "-1 = dry, 1 = wet");
		interface->addVerticalSlider("Dry/Wet Mix", &fslider0, 0.0f, -1.0f, 1.0f, 0.01f);
		interface->declare(&fslider10, "2", "");
		interface->declare(&fslider10, "style", "knob");
		interface->declare(&fslider10, "tooltip", "Output scale factor");
		interface->declare(&fslider10, "unit", "dB");
		interface->addVerticalSlider("Level", &fslider10, -2e+01f, -7e+01f, 4e+01f, 0.1f);
		interface->closeBox();
		interface->closeBox();
	}
	virtual void compute (int count, FAUSTFLOAT** input, FAUSTFLOAT** output) {
		float 	fSlow0 = (0.0010000000000000009f * float(fslider0));
		float 	fSlow1 = (1.0f / tanf((fConst1 * float(fslider1))));
		float 	fSlow2 = (1 + fSlow1);
		float 	fSlow3 = (1.0f / fSlow2);
		float 	fSlow4 = (0 - ((1 - fSlow1) / fSlow2));
		float 	fSlow5 = float(fslider2);
		float 	fSlow6 = expf((fConst3 / fSlow5));
		float 	fSlow7 = float(fslider3);
		float 	fSlow8 = ((expf((fConst3 / fSlow7)) / fSlow6) - 1);
		float 	fSlow9 = faustpower<2>(fSlow6);
		float 	fSlow10 = (1.0f - fSlow9);
		float 	fSlow11 = cosf((fConst4 * float(fslider4)));
		float 	fSlow12 = (1.0f - (fSlow11 * fSlow9));
		float 	fSlow13 = (fSlow12 / fSlow10);
		float 	fSlow14 = sqrtf(max((float)0, ((faustpower<2>(fSlow12) / faustpower<2>(fSlow10)) - 1.0f)));
		float 	fSlow15 = (fSlow6 * ((1.0f + fSlow14) - fSlow13));
		float 	fSlow16 = (fSlow13 - fSlow14);
		int 	iSlow17 = int((int((fConst7 * float(fslider5))) & 8191));
		float 	fSlow18 = expf((fConst10 / fSlow5));
		float 	fSlow19 = ((expf((fConst10 / fSlow7)) / fSlow18) - 1);
		float 	fSlow20 = faustpower<2>(fSlow18);
		float 	fSlow21 = (1.0f - fSlow20);
		float 	fSlow22 = (1.0f - (fSlow11 * fSlow20));
		float 	fSlow23 = (fSlow22 / fSlow21);
		float 	fSlow24 = sqrtf(max((float)0, ((faustpower<2>(fSlow22) / faustpower<2>(fSlow21)) - 1.0f)));
		float 	fSlow25 = (fSlow18 * ((1.0f + fSlow24) - fSlow23));
		float 	fSlow26 = (fSlow23 - fSlow24);
		float 	fSlow27 = expf((fConst15 / fSlow5));
		float 	fSlow28 = ((expf((fConst15 / fSlow7)) / fSlow27) - 1);
		float 	fSlow29 = faustpower<2>(fSlow27);
		float 	fSlow30 = (1.0f - fSlow29);
		float 	fSlow31 = (1.0f - (fSlow11 * fSlow29));
		float 	fSlow32 = (fSlow31 / fSlow30);
		float 	fSlow33 = sqrtf(max((float)0, ((faustpower<2>(fSlow31) / faustpower<2>(fSlow30)) - 1.0f)));
		float 	fSlow34 = (fSlow27 * ((1.0f + fSlow33) - fSlow32));
		float 	fSlow35 = (fSlow32 - fSlow33);
		float 	fSlow36 = expf((fConst20 / fSlow5));
		float 	fSlow37 = ((expf((fConst20 / fSlow7)) / fSlow36) - 1);
		float 	fSlow38 = faustpower<2>(fSlow36);
		float 	fSlow39 = (1.0f - fSlow38);
		float 	fSlow40 = (1.0f - (fSlow11 * fSlow38));
		float 	fSlow41 = (fSlow40 / fSlow39);
		float 	fSlow42 = sqrtf(max((float)0, ((faustpower<2>(fSlow40) / faustpower<2>(fSlow39)) - 1.0f)));
		float 	fSlow43 = (fSlow36 * ((1.0f + fSlow42) - fSlow41));
		float 	fSlow44 = (fSlow41 - fSlow42);
		float 	fSlow45 = expf((fConst25 / fSlow5));
		float 	fSlow46 = ((expf((fConst25 / fSlow7)) / fSlow45) - 1);
		float 	fSlow47 = faustpower<2>(fSlow45);
		float 	fSlow48 = (1.0f - fSlow47);
		float 	fSlow49 = (1.0f - (fSlow11 * fSlow47));
		float 	fSlow50 = (fSlow49 / fSlow48);
		float 	fSlow51 = sqrtf(max((float)0, ((faustpower<2>(fSlow49) / faustpower<2>(fSlow48)) - 1.0f)));
		float 	fSlow52 = (fSlow45 * ((1.0f + fSlow51) - fSlow50));
		float 	fSlow53 = (fSlow50 - fSlow51);
		float 	fSlow54 = expf((fConst30 / fSlow5));
		float 	fSlow55 = ((expf((fConst30 / fSlow7)) / fSlow54) - 1);
		float 	fSlow56 = faustpower<2>(fSlow54);
		float 	fSlow57 = (1.0f - fSlow56);
		float 	fSlow58 = (1.0f - (fSlow11 * fSlow56));
		float 	fSlow59 = (fSlow58 / fSlow57);
		float 	fSlow60 = sqrtf(max((float)0, ((faustpower<2>(fSlow58) / faustpower<2>(fSlow57)) - 1.0f)));
		float 	fSlow61 = (fSlow54 * ((1.0f + fSlow60) - fSlow59));
		float 	fSlow62 = (fSlow59 - fSlow60);
		float 	fSlow63 = expf((fConst35 / fSlow5));
		float 	fSlow64 = ((expf((fConst35 / fSlow7)) / fSlow63) - 1);
		float 	fSlow65 = faustpower<2>(fSlow63);
		float 	fSlow66 = (1.0f - fSlow65);
		float 	fSlow67 = (1.0f - (fSlow11 * fSlow65));
		float 	fSlow68 = (fSlow67 / fSlow66);
		float 	fSlow69 = sqrtf(max((float)0, ((faustpower<2>(fSlow67) / faustpower<2>(fSlow66)) - 1.0f)));
		float 	fSlow70 = (fSlow63 * ((1.0f + fSlow69) - fSlow68));
		float 	fSlow71 = (fSlow68 - fSlow69);
		float 	fSlow72 = expf((fConst40 / fSlow5));
		float 	fSlow73 = ((expf((fConst40 / fSlow7)) / fSlow72) - 1);
		float 	fSlow74 = faustpower<2>(fSlow72);
		float 	fSlow75 = (1.0f - fSlow74);
		float 	fSlow76 = (1.0f - (fSlow74 * fSlow11));
		float 	fSlow77 = (fSlow76 / fSlow75);
		float 	fSlow78 = sqrtf(max((float)0, ((faustpower<2>(fSlow76) / faustpower<2>(fSlow75)) - 1.0f)));
		float 	fSlow79 = (fSlow72 * ((1.0f + fSlow78) - fSlow77));
		float 	fSlow80 = (fSlow77 - fSlow78);
		float 	fSlow81 = powf(10,(0.05f * float(fslider6)));
		float 	fSlow82 = float(fslider7);
		float 	fSlow83 = (fConst44 * (fSlow82 / sqrtf(max((float)0, fSlow81))));
		float 	fSlow84 = ((1.0f - fSlow83) / (1.0f + fSlow83));
		float 	fSlow85 = ((1 + fSlow84) * (0 - cosf((fConst44 * fSlow82))));
		float 	fSlow86 = powf(10,(0.05f * float(fslider8)));
		float 	fSlow87 = float(fslider9);
		float 	fSlow88 = (fConst44 * (fSlow87 / sqrtf(max((float)0, fSlow86))));
		float 	fSlow89 = ((1.0f - fSlow88) / (1.0f + fSlow88));
		float 	fSlow90 = ((1 + fSlow89) * (0 - cosf((fConst44 * fSlow87))));
		float 	fSlow91 = (0.0010000000000000009f * powf(10,(0.05f * float(fslider10))));
		FAUSTFLOAT* input0 = input[0];
		FAUSTFLOAT* input1 = input[1];
		FAUSTFLOAT* output0 = output[0];
		FAUSTFLOAT* output1 = output[1];
		for (int i=0; i<count; i++) {
			fRec0[0] = ((0.999f * fRec0[1]) + fSlow0);
			float fTemp0 = (1.0f + fRec0[0]);
			float fTemp1 = (1.0f - (0.5f * fTemp0));
			float fTemp2 = (float)input0[i];
			fVec0[IOTA&8191] = fTemp2;
			fRec12[0] = ((fSlow4 * fRec12[1]) + (fSlow3 * (fRec5[1] + fRec5[2])));
			fRec11[0] = ((fSlow16 * fRec11[1]) + (fSlow15 * (fRec5[1] + (fSlow8 * fRec12[0]))));
			fVec1[IOTA&8191] = (1e-20f + (0.35355339059327373f * fRec11[0]));
			float fTemp3 = (0.3f * fVec0[(IOTA-iSlow17)&8191]);
			float fTemp4 = ((fTemp3 + fVec1[(IOTA-iConst6)&8191]) - (0.6f * fRec9[1]));
			fVec2[IOTA&2047] = fTemp4;
			fRec9[0] = fVec2[(IOTA-iConst8)&2047];
			float 	fRec10 = (0.6f * fVec2[IOTA&2047]);
			fRec16[0] = ((fSlow4 * fRec16[1]) + (fSlow3 * (fRec1[1] + fRec1[2])));
			fRec15[0] = ((fSlow26 * fRec15[1]) + (fSlow25 * (fRec1[1] + (fSlow19 * fRec16[0]))));
			fVec3[IOTA&8191] = (1e-20f + (0.35355339059327373f * fRec15[0]));
			float fTemp5 = ((fVec3[(IOTA-iConst12)&8191] + fTemp3) - (0.6f * fRec13[1]));
			fVec4[IOTA&1023] = fTemp5;
			fRec13[0] = fVec4[(IOTA-iConst13)&1023];
			float 	fRec14 = (0.6f * fVec4[IOTA&1023]);
			float fTemp6 = (fRec14 + fRec10);
			fRec20[0] = ((fSlow4 * fRec20[1]) + (fSlow3 * (fRec3[1] + fRec3[2])));
			fRec19[0] = ((fSlow35 * fRec19[1]) + (fSlow34 * (fRec3[1] + (fSlow28 * fRec20[0]))));
			fVec5[IOTA&8191] = (1e-20f + (0.35355339059327373f * fRec19[0]));
			float fTemp7 = (fVec5[(IOTA-iConst17)&8191] - (fTemp3 + (0.6f * fRec17[1])));
			fVec6[IOTA&2047] = fTemp7;
			fRec17[0] = fVec6[(IOTA-iConst18)&2047];
			float 	fRec18 = (0.6f * fVec6[IOTA&2047]);
			fRec24[0] = ((fSlow4 * fRec24[1]) + (fSlow3 * (fRec7[1] + fRec7[2])));
			fRec23[0] = ((fSlow44 * fRec23[1]) + (fSlow43 * (fRec7[1] + (fSlow37 * fRec24[0]))));
			fVec7[IOTA&8191] = (1e-20f + (0.35355339059327373f * fRec23[0]));
			float fTemp8 = (fVec7[(IOTA-iConst22)&8191] - (fTemp3 + (0.6f * fRec21[1])));
			fVec8[IOTA&1023] = fTemp8;
			fRec21[0] = fVec8[(IOTA-iConst23)&1023];
			float 	fRec22 = (0.6f * fVec8[IOTA&1023]);
			float fTemp9 = (fRec22 + (fRec18 + fTemp6));
			fRec28[0] = ((fSlow4 * fRec28[1]) + (fSlow3 * (fRec2[1] + fRec2[2])));
			fRec27[0] = ((fSlow53 * fRec27[1]) + (fSlow52 * (fRec2[1] + (fSlow46 * fRec28[0]))));
			fVec9[IOTA&16383] = (1e-20f + (0.35355339059327373f * fRec27[0]));
			float fTemp10 = (float)input1[i];
			fVec10[IOTA&8191] = fTemp10;
			float fTemp11 = (0.3f * fVec10[(IOTA-iSlow17)&8191]);
			float fTemp12 = (fTemp11 + ((0.6f * fRec25[1]) + fVec9[(IOTA-iConst27)&16383]));
			fVec11[IOTA&2047] = fTemp12;
			fRec25[0] = fVec11[(IOTA-iConst28)&2047];
			float 	fRec26 = (0 - (0.6f * fVec11[IOTA&2047]));
			fRec32[0] = ((fSlow4 * fRec32[1]) + (fSlow3 * (fRec6[1] + fRec6[2])));
			fRec31[0] = ((fSlow62 * fRec31[1]) + (fSlow61 * (fRec6[1] + (fSlow55 * fRec32[0]))));
			fVec12[IOTA&8191] = (1e-20f + (0.35355339059327373f * fRec31[0]));
			float fTemp13 = (fVec12[(IOTA-iConst32)&8191] + (fTemp11 + (0.6f * fRec29[1])));
			fVec13[IOTA&2047] = fTemp13;
			fRec29[0] = fVec13[(IOTA-iConst33)&2047];
			float 	fRec30 = (0 - (0.6f * fVec13[IOTA&2047]));
			fRec36[0] = ((fSlow4 * fRec36[1]) + (fSlow3 * (fRec4[1] + fRec4[2])));
			fRec35[0] = ((fSlow71 * fRec35[1]) + (fSlow70 * (fRec4[1] + (fSlow64 * fRec36[0]))));
			fVec14[IOTA&16383] = (1e-20f + (0.35355339059327373f * fRec35[0]));
			float fTemp14 = (((0.6f * fRec33[1]) + fVec14[(IOTA-iConst37)&16383]) - fTemp11);
			fVec15[IOTA&2047] = fTemp14;
			fRec33[0] = fVec15[(IOTA-iConst38)&2047];
			float 	fRec34 = (0 - (0.6f * fVec15[IOTA&2047]));
			fRec40[0] = ((fSlow4 * fRec40[1]) + (fSlow3 * (fRec8[1] + fRec8[2])));
			fRec39[0] = ((fSlow80 * fRec39[1]) + (fSlow79 * (fRec8[1] + (fSlow73 * fRec40[0]))));
			fVec16[IOTA&16383] = (1e-20f + (0.35355339059327373f * fRec39[0]));
			float fTemp15 = (((0.6f * fRec37[1]) + fVec16[(IOTA-iConst42)&16383]) - fTemp11);
			fVec17[IOTA&1023] = fTemp15;
			fRec37[0] = fVec17[(IOTA-iConst43)&1023];
			float 	fRec38 = (0 - (0.6f * fVec17[IOTA&1023]));
			fRec1[0] = (fRec37[1] + (fRec33[1] + (fRec29[1] + (fRec25[1] + (fRec21[1] + (fRec17[1] + (fRec9[1] + (fRec13[1] + (fRec38 + (fRec34 + (fRec30 + (fRec26 + fTemp9))))))))))));
			fRec2[0] = (0 - ((fRec37[1] + (fRec33[1] + (fRec29[1] + (fRec25[1] + (fRec38 + (fRec34 + (fRec26 + fRec30))))))) - (fRec21[1] + (fRec17[1] + (fRec9[1] + (fRec13[1] + fTemp9))))));
			float fTemp16 = (fRec18 + fRec22);
			fRec3[0] = (0 - ((fRec37[1] + (fRec33[1] + (fRec21[1] + (fRec17[1] + (fRec38 + (fRec34 + fTemp16)))))) - (fRec29[1] + (fRec25[1] + (fRec9[1] + (fRec13[1] + (fRec30 + (fRec26 + fTemp6))))))));
			fRec4[0] = (0 - ((fRec29[1] + (fRec25[1] + (fRec21[1] + (fRec17[1] + (fRec30 + (fRec26 + fTemp16)))))) - (fRec37[1] + (fRec33[1] + (fRec9[1] + (fRec13[1] + (fRec38 + (fRec34 + fTemp6))))))));
			float fTemp17 = (fRec14 + fRec18);
			float fTemp18 = (fRec10 + fRec22);
			fRec5[0] = (0 - ((fRec37[1] + (fRec29[1] + (fRec21[1] + (fRec9[1] + (fRec38 + (fRec30 + fTemp18)))))) - (fRec33[1] + (fRec25[1] + (fRec17[1] + (fRec13[1] + (fRec34 + (fRec26 + fTemp17))))))));
			fRec6[0] = (0 - ((fRec33[1] + (fRec25[1] + (fRec21[1] + (fRec9[1] + (fRec34 + (fRec26 + fTemp18)))))) - (fRec37[1] + (fRec29[1] + (fRec17[1] + (fRec13[1] + (fRec38 + (fRec30 + fTemp17))))))));
			float fTemp19 = (fRec14 + fRec22);
			float fTemp20 = (fRec10 + fRec18);
			fRec7[0] = (0 - ((fRec33[1] + (fRec29[1] + (fRec17[1] + (fRec9[1] + (fRec34 + (fRec30 + fTemp20)))))) - (fRec37[1] + (fRec25[1] + (fRec21[1] + (fRec13[1] + (fRec38 + (fRec26 + fTemp19))))))));
			fRec8[0] = (0 - ((fRec37[1] + (fRec25[1] + (fRec17[1] + (fRec9[1] + (fRec38 + (fRec26 + fTemp20)))))) - (fRec33[1] + (fRec29[1] + (fRec21[1] + (fRec13[1] + (fRec34 + (fRec30 + fTemp19))))))));
			float fTemp21 = (0.37f * (fRec2[0] + fRec3[0]));
			float fTemp22 = (fSlow85 * fRec41[1]);
			fRec41[0] = (0 - ((fTemp22 + (fSlow84 * fRec41[2])) - fTemp21));
			float fTemp23 = (fSlow84 * fRec41[0]);
			float fTemp24 = (0.5f * ((fTemp23 + (fRec41[2] + (fTemp21 + fTemp22))) + (fSlow81 * ((fTemp23 + (fTemp22 + fRec41[2])) - fTemp21))));
			float fTemp25 = (fSlow90 * fRec42[1]);
			fRec42[0] = (0 - ((fTemp25 + (fSlow89 * fRec42[2])) - fTemp24));
			float fTemp26 = (fSlow89 * fRec42[0]);
			fRec43[0] = ((0.999f * fRec43[1]) + fSlow91);
			output0[i] = (FAUSTFLOAT)(fRec43[0] * ((0.25f * (((fTemp26 + (fRec42[2] + (fTemp24 + fTemp25))) + (fSlow86 * (((fTemp25 + fRec42[2]) + fTemp26) - fTemp24))) * fTemp0)) + (fVec0[IOTA&8191] * fTemp1)));
			float fTemp27 = (0.37f * (fRec2[0] - fRec3[0]));
			float fTemp28 = (fSlow85 * fRec44[1]);
			fRec44[0] = (0 - ((fTemp28 + (fSlow84 * fRec44[2])) - fTemp27));
			float fTemp29 = (fSlow84 * fRec44[0]);
			float fTemp30 = (0.5f * ((fTemp29 + (fRec44[2] + (fTemp27 + fTemp28))) + (fSlow81 * ((fTemp29 + (fTemp28 + fRec44[2])) - fTemp27))));
			float fTemp31 = (fSlow90 * fRec45[1]);
			fRec45[0] = (0 - ((fTemp31 + (fSlow89 * fRec45[2])) - fTemp30));
			float fTemp32 = (fSlow89 * fRec45[0]);
			output1[i] = (FAUSTFLOAT)(fRec43[0] * ((0.25f * (fTemp0 * ((fTemp32 + (fRec45[2] + (fTemp31 + fTemp30))) + (fSlow86 * ((fTemp32 + (fTemp31 + fRec45[2])) - fTemp30))))) + (fVec10[IOTA&8191] * fTemp1)));
			// post processing
			fRec45[2] = fRec45[1]; fRec45[1] = fRec45[0];
			fRec44[2] = fRec44[1]; fRec44[1] = fRec44[0];
			fRec43[1] = fRec43[0];
			fRec42[2] = fRec42[1]; fRec42[1] = fRec42[0];
			fRec41[2] = fRec41[1]; fRec41[1] = fRec41[0];
			fRec8[2] = fRec8[1]; fRec8[1] = fRec8[0];
			fRec7[2] = fRec7[1]; fRec7[1] = fRec7[0];
			fRec6[2] = fRec6[1]; fRec6[1] = fRec6[0];
			fRec5[2] = fRec5[1]; fRec5[1] = fRec5[0];
			fRec4[2] = fRec4[1]; fRec4[1] = fRec4[0];
			fRec3[2] = fRec3[1]; fRec3[1] = fRec3[0];
			fRec2[2] = fRec2[1]; fRec2[1] = fRec2[0];
			fRec1[2] = fRec1[1]; fRec1[1] = fRec1[0];
			fRec37[1] = fRec37[0];
			fRec39[1] = fRec39[0];
			fRec40[1] = fRec40[0];
			fRec33[1] = fRec33[0];
			fRec35[1] = fRec35[0];
			fRec36[1] = fRec36[0];
			fRec29[1] = fRec29[0];
			fRec31[1] = fRec31[0];
			fRec32[1] = fRec32[0];
			fRec25[1] = fRec25[0];
			fRec27[1] = fRec27[0];
			fRec28[1] = fRec28[0];
			fRec21[1] = fRec21[0];
			fRec23[1] = fRec23[0];
			fRec24[1] = fRec24[0];
			fRec17[1] = fRec17[0];
			fRec19[1] = fRec19[0];
			fRec20[1] = fRec20[0];
			fRec13[1] = fRec13[0];
			fRec15[1] = fRec15[0];
			fRec16[1] = fRec16[0];
			fRec9[1] = fRec9[0];
			fRec11[1] = fRec11[0];
			fRec12[1] = fRec12[0];
			IOTA = IOTA+1;
			fRec0[1] = fRec0[0];
		}
	}
};



/***************************END USER SECTION ***************************/

/*******************BEGIN ARCHITECTURE SECTION (part 2/2)***************/


/* Faust code wrapper ------- */

#include "ext.h"
#include "ext_obex.h"
#include "z_dsp.h"
#include "jpatcher_api.h"
#include <string.h>

#define ASSIST_INLET 	1  		/* should be defined somewhere ?? */
#define ASSIST_OUTLET 	2		/* should be defined somewhere ?? */

#define EXTERNAL_VERSION "0.55"

class mspUI;

struct Max_Meta1 : Meta
{
    int fCount;
    
    Max_Meta1():fCount(0)
    {}
     
    void declare(const char* key, const char* value)
    {
        if ((strcmp("name", key) == 0) || (strcmp("author", key) == 0)) {
            fCount++;
        }
    }
};

struct Max_Meta2 : Meta
{
    void declare(const char* key, const char* value)
    {
        if ((strcmp("name", key) == 0) || (strcmp("author", key) == 0)) {
            post("%s : %s", key, value);
        }
    }
};


/*--------------------------------------------------------------------------*/
typedef struct faust
{
    t_pxobject m_ob;
    t_atom *m_seen, *m_want;
    map<string, t_object*> m_output_table;
    short m_where;
    bool m_mute;
    void** args;
    mspUI* dspUI;
    mydsp* dsp;
    char* m_json;                
} t_faust;

void *faust_class;

/*--------------------------------------------------------------------------*/
class mspUIObject {
    
protected:
    
    string fLabel;
    FAUSTFLOAT* fZone;
    
    FAUSTFLOAT range(FAUSTFLOAT min, FAUSTFLOAT max, FAUSTFLOAT val) {return (val < min) ? min : (val > max) ? max : val;}
    
public:
    
    mspUIObject(const string& label, FAUSTFLOAT* zone):fLabel(label),fZone(zone) {}
    virtual ~mspUIObject() {}
    
    virtual void setValue(FAUSTFLOAT f) {*fZone = range(0.0, 1.0, f);}
    virtual FAUSTFLOAT getValue() { return *fZone; }
    virtual void toString(char* buffer) {}
    virtual string getName() {return fLabel;}
  
};

/*--------------------------------------------------------------------------*/
class mspCheckButton : public mspUIObject {
    
    public:
        
        mspCheckButton(const string& label, FAUSTFLOAT* zone):mspUIObject(label,zone) {}
        virtual ~mspCheckButton() {}
        
        void toString(char* buffer)
        {
            snprintf(buffer, 256, "CheckButton(float): %s", fLabel.c_str());
        }
};

/*--------------------------------------------------------------------------*/
class mspButton : public mspUIObject {
    
    public:
        
        mspButton(const string& label, FAUSTFLOAT* zone):mspUIObject(label, zone) {}
        virtual ~mspButton() {}
        
        void toString(char* buffer)
        {
            snprintf(buffer, 256, "Button(float): %s", fLabel.c_str());
        }
};

/*--------------------------------------------------------------------------*/
class mspSlider : public mspUIObject {
    
    private:
        
        FAUSTFLOAT fInit;
        FAUSTFLOAT fMin;
        FAUSTFLOAT fMax;
        FAUSTFLOAT fStep;
        
    public:
        
        mspSlider(const string& label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT min, FAUSTFLOAT max, FAUSTFLOAT step)
        :mspUIObject(label,zone),fInit(init),fMin(min),fMax(max),fStep(step) {}
        virtual ~mspSlider() {}
        
        void toString(char* buffer)
        {
            stringstream s; 
            s << "Slider(float): " << fLabel << " [init=" << fInit << ":min=" << fMin << ":max=" << fMax << ":step=" << fStep << ":cur=" << *fZone << "]";
            strcpy(buffer, s.str().c_str());
        }
        
        void setValue(FAUSTFLOAT f) {*fZone = range(fMin, fMax, f);}
};

/*--------------------------------------------------------------------------*/
class mspBargraph : public mspUIObject {
    
    private:
        
        FAUSTFLOAT fMin;
        FAUSTFLOAT fMax;
        FAUSTFLOAT fCurrent;
        
    public:
        
        mspBargraph(const string& label, FAUSTFLOAT* zone, FAUSTFLOAT min, FAUSTFLOAT max)
        :mspUIObject(label,zone),fMin(min),fMax(max),fCurrent(*zone) {}
        virtual ~mspBargraph() {}
        
        void toString(char* buffer)
        {
            stringstream s; 
            s << "Bargraph(float): " << fLabel << " [min=" << fMin << ":max=" << fMax << ":cur=" << *fZone << "]";
            strcpy(buffer, s.str().c_str());
        }
        
        virtual FAUSTFLOAT getValue() 
        { 
            if (*fZone != fCurrent) {
                fCurrent = *fZone;
                return fCurrent;
            } else {
                return NAN; 
            }
        }
};

/*--------------------------------------------------------------------------*/
class mspUI : public UI
{

    private:
        
        map<string, mspUIObject*> fUITable1;       // Table using labels
        map<string, mspUIObject*> fUITable2;       // Table using complete path
        map<string, mspUIObject*> fUITable3;       // Table containing bargraph
         
        map<const char*, const char*> fDeclareTable;
        std::vector<std::string> fControlsLevel;
        
        std::string buildPath(const std::string& label) 
        {
            std::string res = "/";
            for (size_t i = 0; i < fControlsLevel.size(); i++) {
                res += fControlsLevel[i];
                res += "/";
            }
            res += label;
            replace(res.begin(), res.end(), ' ', '_');
            return res;
        }
    
        string createLabel(const char* label)
        {
            map<const char*, const char*>::reverse_iterator it;
            if (fDeclareTable.size() > 0) {
                unsigned int i = 0;
                string res = string(label);
                char sep = '[';
                for (it = fDeclareTable.rbegin(); it != fDeclareTable.rend(); it++, i++) {
                    res = res + sep + (*it).first + ":" + (*it).second;
                    sep = ',';
                }
                res += ']';
                fDeclareTable.clear();
                return res;
            } else {
                return string(label);
            }
        }
        
    public:
        
        typedef map<string, mspUIObject*>::iterator iterator;
        
        mspUI() {}
        virtual ~mspUI()
        {
            clear();
        }
        
        void addButton(const char* label, FAUSTFLOAT* zone) 
        {
            mspUIObject* obj = new mspButton(createLabel(label), zone);
            fUITable1[string(label)] = obj;
            fUITable2[buildPath(label)] = obj;
        }
        
        void addCheckButton(const char* label, FAUSTFLOAT* zone) 
        {
            mspUIObject* obj = new mspCheckButton(createLabel(label), zone);
            fUITable1[string(label)] = obj;
            fUITable2[buildPath(label)] = obj; 
        }
        
        void addSlider(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT min, FAUSTFLOAT max, FAUSTFLOAT step)
        {
            mspUIObject* obj = new mspSlider(createLabel(label), zone, init, min, max, step);
            fUITable1[string(label)] = obj;
            fUITable2[buildPath(label)] = obj; 
        }
        
        void addVerticalSlider(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT min, FAUSTFLOAT max, FAUSTFLOAT step)
        {
            addSlider(label, zone, init, min, max, step);
        }
        
        void addHorizontalSlider(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT min, FAUSTFLOAT max, FAUSTFLOAT step)
        {
            addSlider(label, zone, init, min, max, step);
        }
        
        void addNumEntry(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT min, FAUSTFLOAT max, FAUSTFLOAT step)
        {
            mspUIObject* obj = new mspSlider(createLabel(label), zone, init, min, max, step);
            fUITable1[string(label)] = obj;
            fUITable2[buildPath(label)] = obj;
        }
        
        void addHorizontalBargraph(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT min, FAUSTFLOAT max) 
        {   
            fUITable3[buildPath(label)] = new mspBargraph(createLabel(label), zone, min, max);
            fDeclareTable.clear();
        }
        void addVerticalBargraph(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT min, FAUSTFLOAT max) 
        {
            fUITable3[buildPath(label)] = new mspBargraph(createLabel(label), zone, min, max);
            fDeclareTable.clear();
        }
    
        void openTabBox(const char* label) {fControlsLevel.push_back(label); fDeclareTable.clear();}
        void openHorizontalBox(const char* label) {fControlsLevel.push_back(label); fDeclareTable.clear();}
        void openVerticalBox(const char* label) {fControlsLevel.push_back(label); fDeclareTable.clear();}
        void closeBox() {fControlsLevel.pop_back(); fDeclareTable.clear();}
        
        virtual void declare(FAUSTFLOAT* zone, const char* key, const char* val)
        {
            fDeclareTable[key] = val;
        }
       
        bool isValue(string name) 
        {
            return (fUITable1.count(name) || fUITable2.count(name));
        }
        bool isOutputValue(string name) 
        {
            return fUITable3.count(name);
        }
        bool isInputValue(string name) 
        {
            return fUITable2.count(name);
        }
        bool setValue(string name, FAUSTFLOAT f)
        {
            if (fUITable1.count(name)) {
                fUITable1[name]->setValue(f);
                return true;
            } else if (fUITable2.count(name)) {
                fUITable2[name]->setValue(f);
                return true;
            } else {
                return false;
            }
        }
        
        FAUSTFLOAT getOutputValue(string name) { return fUITable3[name]->getValue(); }
          
        iterator begin1()	{ return fUITable1.begin(); }
        iterator end1()		{ return fUITable1.end(); }
        
        iterator begin2()	{ return fUITable2.begin(); }
        iterator end2()		{ return fUITable2.end(); }
        
        int itemsCount() { return fUITable1.size(); }
        void clear() 
        { 
            iterator it;
            for (it = begin1(); it != end1(); it++) {
                delete (*it).second;
            }
            fUITable1.clear(); 
            fUITable2.clear(); 
        }
    
};

//--------------------------------------------------------------------------
static bool check_digit(const string& name)
{
    for (int i = name.size() - 1; i >= 0; i--) {
        if (isdigit(name[i])) return true;
    }
    return false;
}

static int count_digit(const string& name)
{
    int count = 0;
    for (int i = name.size() - 1; i >= 0; i--) {
        if (isdigit(name[i])) count++;
    }
    return count;
}

void faust_anything(t_faust* obj, t_symbol* s, short ac, t_atom* av)
{
    bool res = false;
    string name = string((s)->s_name);
     
    if (ac < 0) return;
    
    // Check if no argument is there, consider it is a toggle message for a button
    if (ac == 0 && obj->dspUI->isValue(name)) {
        
        string name = string((s)->s_name);
        float off = 0.0f;
        float on = 1.0f;
        obj->dspUI->setValue(name, off);
        obj->dspUI->setValue(name, on);
        
        av[0].a_type = A_FLOAT;
        av[0].a_w.w_float = off;
        faust_anything(obj, s, 1, av);
        
        return;
    }
    
    // List of values
    if (check_digit(name)) {
        
        int ndigit = 0;
        int pos;
        
        for (pos = name.size() - 1; pos >= 0; pos--) {
            if (isdigit(name[pos]) || name[pos] == ' ') {
                ndigit++;
            } else {
                break;
            }
        }
        pos++;
        
        string prefix = name.substr(0, pos);
        string num_base = name.substr(pos);
        int num = atoi(num_base.c_str());
        
        int i;
        t_atom* ap;
       
        // Increment ap each time to get to the next atom
        for (i = 0, ap = av; i < ac; i++, ap++) {
            float value;
            switch (atom_gettype(ap)) {
                case A_LONG: {
                    value = (float)ap[0].a_w.w_long;
                    break;
                }
                case A_FLOAT:
                    value = ap[0].a_w.w_float;
                    break;
                    
                default:
                    post("Invalid argument in parameter setting"); 
                    return;         
            }
            
            stringstream num_val;
            num_val << num + i;
            char param_name[256];
            
            switch (ndigit - count_digit(num_val.str())) {
                case 0: 
                    sprintf(param_name, "%s%s", prefix.c_str(), num_val.str().c_str());
                    break;
                case 1: 
                    sprintf(param_name, "%s %s", prefix.c_str(), num_val.str().c_str());
                    break;
                case 2: 
                    sprintf(param_name, "%s  %s", prefix.c_str(), num_val.str().c_str());
                    break;
            }
            
            // Try special naming scheme for list of parameters
            res = obj->dspUI->setValue(param_name, value); 
            
            // Otherwise try standard name
            if (!res) {
                res = obj->dspUI->setValue(name, value);
            }
            
            if (!res) {
                post("Unknown parameter : %s", (s)->s_name);
            }
        }
    } else {
        // Standard parameter name
        float value = (av[0].a_type == A_LONG) ? (float)av[0].a_w.w_long : av[0].a_w.w_float;
        res = obj->dspUI->setValue(name, value); 
    }
    
    if (!res) {
        post("Unknown parameter : %s", (s)->s_name);
    }
}

/*--------------------------------------------------------------------------*/
void faust_create_jsui(t_faust* x)
{
    t_object *patcher, *box, *obj;
    object_obex_lookup((t_object*)x, gensym("#P"), &patcher);
    
    for (box = jpatcher_get_firstobject(patcher); box; box = jbox_get_nextobject(box)) {
        obj = jbox_get_object(box);
        // Notify JSON
        if (obj && strcmp(object_classname(obj)->s_name, "js") == 0) {
            t_atom json;
            atom_setsym(&json, gensym(x->m_json));
            object_method_typed(obj, gensym("anything"), 1, &json, 0);
            post("Generate UI from JSON...");
        }
    }
        
    // Keep all outputs
    x->m_output_table.clear();
    for (box = jpatcher_get_firstobject(patcher); box; box = jbox_get_nextobject(box)) {
        obj = jbox_get_object(box);
        t_symbol *scriptingname = jbox_get_varname(obj); // scripting name
        if (scriptingname && x->dspUI->isOutputValue(scriptingname->s_name)) {
            x->m_output_table[scriptingname->s_name] = obj;
        }
    }
}

void faust_update_outputs(t_faust* x)
{
    map<string, t_object*>::iterator it;
    for (it =  x->m_output_table.begin(); it != x->m_output_table.end(); it++) {
        FAUSTFLOAT value = x->dspUI->isOutputValue((*it).first);
        if (value != NAN) {
            t_atom at_value;
            atom_setfloat(&at_value, value);
            object_method_typed((*it).second, gensym("float"), 1, &at_value, 0);
        }
    }
}

/*--------------------------------------------------------------------------*/
void* faust_new(t_symbol* s, short ac, t_atom* av)
{
    t_faust* x = (t_faust*)newobject(faust_class);

    x->m_mute = false;

    x->dsp = new mydsp();
    x->dspUI = new mspUI();

    x->dsp->init(long(sys_getsr()));
    x->dsp->buildUserInterface(x->dspUI);
    
    // Prepare JSON
    
    JSONUI builder(x->dsp->getNumInputs(), x->dsp->getNumOutputs());
    x->dsp->metadata(&builder);
    x->dsp->buildUserInterface(&builder);
    x->m_json = strdup(builder.JSON().c_str());
    
    x->args = (void**)calloc((x->dsp->getNumInputs()+x->dsp->getNumOutputs())+2, sizeof(void*));

    /* Multi in */
    dsp_setup((t_pxobject*)x, x->dsp->getNumInputs());

    /* Multi out */
    for (int i = 0; i< x->dsp->getNumOutputs(); i++) {
        outlet_new((t_pxobject*)x, (char*)"signal");
    }

    ((t_pxobject*)x)->z_misc = Z_NO_INPLACE; // To assure input and output buffers are actually different
    
    // send JSON to JS script
    faust_create_jsui(x);
    return x;
}

/*--------------------------------------------------------------------------*/
void faust_assist(t_faust* x, void* b, long msg, long a, char* dst)
{
    if (msg == ASSIST_INLET) {
        if (a == 0) {
            if (x->dsp->getNumInputs() == 0) {
                sprintf(dst, "(signal) : Unused Input");
            } else {
                sprintf(dst, "(signal) : Audio Input %ld", (a+1));
			}
			post((char*)"------------------");
			for (mspUI::iterator it = x->dspUI->begin1(); it != x->dspUI->end1(); ++it) {
				char param[256];
				it->second->toString(param);
				post(param);
			}
        } else if (a < x->dsp->getNumInputs()) {
            sprintf(dst, "(signal) : Audio Input %ld", (a+1));
        }
    } else if (msg == ASSIST_OUTLET) {
        sprintf(dst, "(signal) : Audio Output %ld", (a+1));
    }
}

/*--------------------------------------------------------------------------*/
void faust_mute(t_faust* obj, t_symbol* s, short ac, t_atom* at)
{
    if (atom_gettype(at) == A_LONG) {
        obj->m_mute = atom_getlong(at);
    }
}

/*--------------------------------------------------------------------------*/
void faust_free(t_faust* x)
{
	dsp_free((t_pxobject*)x);
	if (x->dsp) delete x->dsp;
	if (x->dspUI) delete x->dspUI;
	if (x->args) free(x->args);
    if (x->m_json) free(x->m_json);
}

/*--------------------------------------------------------------------------*/
t_int *faust_perform(t_int *w)
{
	t_faust* x = (t_faust*) (w[1]);
	long n = w[2];
	int offset = 3;
	AVOIDDENORMALS;
    if (x->m_mute) {
        float** outputs = ((float**)&w[offset+x->dsp->getNumInputs()]);
        // Write null buffers to outs
        for (int i = 0; i < x->dsp->getNumOutputs(); i++) {
             memset(outputs[i], 0, sizeof(float) * n);
        }
    } else {
        x->dsp->compute(n, ((float**)&w[offset]), ((float**)&w[offset+x->dsp->getNumInputs()]));
        faust_update_outputs(x);
    }
	return (w + (x->dsp->getNumInputs()+x->dsp->getNumOutputs()) + 2 + 1);
}

/*--------------------------------------------------------------------------*/
void  faust_dsp(t_faust* x, t_signal **sp, short* count)
{
	x->args[0] = x;
	x->args[1] = (void*)sp[0]->s_n;
	for (int i = 0; i<(x->dsp->getNumInputs()+x->dsp->getNumOutputs()); i++) {
		x->args[i + 2] = sp[i]->s_vec;
    }
	dsp_addv(faust_perform, (x->dsp->getNumInputs()+x->dsp->getNumOutputs()) + 2, x->args);
}

/*--------------------------------------------------------------------------*/
extern "C" int main(void)
{
	setup((t_messlist**)&faust_class, (method)faust_new, (method)faust_free,
		(short)sizeof(t_faust), 0L, A_DEFFLOAT, 0);

	dsp* thedsp = new mydsp();
	mspUI dspUI;
 	thedsp->buildUserInterface(&dspUI);
   
    // 03/11/14 : use 'anything' to handle all parameter changes
    addmess((method)faust_anything, (char*)"anything", A_GIMME, 0);

	addmess((method)faust_dsp, (char*)"dsp", A_CANT, 0);
	addmess((method)faust_assist, (char*)"assist", A_CANT, 0);
    addmess((method)faust_mute, (char*)"mute", A_GIMME, 0);
	dsp_initclass();
    
    post((char*)"Faust DSP object 32 bits v%s", EXTERNAL_VERSION);
    post((char*)"Copyright (c) 2012-2014 Grame");
    Max_Meta1 meta1;
    mydsp::metadata(&meta1);
    if (meta1.fCount > 0) {
        Max_Meta2 meta2;
        post("------------------------------");
        mydsp::metadata(&meta2);
        post("------------------------------");
    }

    delete(thedsp);
	return 0;
}

/********************END ARCHITECTURE SECTION (part 2/2)****************/




