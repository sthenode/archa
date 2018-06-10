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
///   File: leaf.hpp
///
/// Author: $author$
///   Date: 6/9/2018
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_APP_CONSOLE_ARCHA_LEAF_HPP
#define _XOS_APP_CONSOLE_ARCHA_LEAF_HPP

#include "xos/app/console/archa/node.hpp"

namespace xos {
namespace app {
namespace console {
namespace archa {

typedef std::tree::leaft<branch, node> leaf_extends;
///////////////////////////////////////////////////////////////////////
///  Class: leaf
///////////////////////////////////////////////////////////////////////
class leaf: public leaf_extends {
public:
    typedef leaf_extends extends;

    leaf(const string_t& path, const string_t& name, fs::entry_type type) {
        construct(path.chars(), name.chars(), type);
    }
    leaf(const string_t& path, const fs::directory::entry& entry) {
        construct(path.chars(), entry);
    }
    leaf(const char* path, const char* name, fs::entry_type type) {
        construct(path, name, type);
    }
    leaf(const char* path, const fs::directory::entry& entry) {
        construct(path, entry);
    }
    leaf(const fs::directory::entry& entry) {
        construct(entry);
    }
    leaf(const leaf& copy) {
        construct(copy);
    }
    leaf() {
        construct();
    }
    virtual ~leaf() {
        destruct();
    }

protected:
    void construct(const char* path, const char* name, fs::entry_type type) {
        construct();
        this->set(path, name, type);
    }
    void construct(const char* path, const fs::directory::entry& entry) {
        construct(entry);
        this->set(path);
    }
    void construct(const fs::directory::entry& entry) {
        extends::construct(entry);
        construct();
    }
    void construct() {
    }
    void destruct() {
    }
    
protected:
};

} /// namespace archa
} /// namespace console
} /// namespace app
} /// namespace xos

#endif /// _XOS_APP_CONSOLE_ARCHA_LEAF_HPP 
