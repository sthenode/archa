///////////////////////////////////////////////////////////////////////
/// Copyright (c) 1988-2018 $organization$
///
/// This software is provided by the author and contributors ``as is'' 
/// and any express or implied warranties, including, but not limited to, 
/// the implied warranties of merchantability and fitness for a particular 
/// purpose are disclaimed. In no event shall the author or contributors 
/// be liable for any direct, indirect, incidental, special, exemplary, 
/// or consequential damages (including, but not limited to, procurement 
/// of substitute goods or services; loss of use, data, or profits; or 
/// business interruption) however caused and on any theory of liability, 
/// whether in contract, strict liability, or tort (including negligence 
/// or otherwise) arising in any way out of the use of this software, 
/// even if advised of the possibility of such damage.
///
///   File: main.hpp
///
/// Author: $author$
///   Date: 4/24/2018
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_APP_CONSOLE_ARCHA_MAIN_HPP
#define _XOS_APP_CONSOLE_ARCHA_MAIN_HPP

#include "xos/console/getopt/main.hpp"
#include "xos/fs/path.hpp"

namespace xos {
namespace app {
namespace console {
namespace archa {

typedef xos::console::getopt::main::implements maint_implements;
typedef xos::console::getopt::main maint_extends;
///////////////////////////////////////////////////////////////////////
///  Class: maint
///////////////////////////////////////////////////////////////////////
template 
<class TImplements = maint_implements, class TExtends = maint_extends>

class _EXPORT_CLASS maint: virtual public TImplements, public TExtends {
public:
    typedef TImplements implements;
    typedef TExtends extends;

    maint() {
    }
    virtual ~maint() {
    }
private:
    maint(const maint &copy) {
    }
    
protected:
    virtual int run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        fs::path path(argv[0]);
        this->outlln("directory = \"", path.directory().chars(), "\"", NULL);
        this->outlln("name = \"", path.file_name().chars(), "\"", NULL);
        this->outlln("extension = \"", path.file_extension().chars(), "\"", NULL);
        return err;
    }
};
typedef maint<> main;

} /// namespace archa
} /// namespace console
} /// namespace app
} /// namespace xos

#endif /// _XOS_APP_CONSOLE_ARCHA_MAIN_HPP 
