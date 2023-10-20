#include "xsd_reader.h"
#include <vector>

namespace xmlgui {
    namespace {

    }

    XSDHandler XSDReader::read_xsd(const std::filesystem::path& file) {
        return XSDHandler(file);
    }
}