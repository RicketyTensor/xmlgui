#pragma once
#include <filesystem>
#include <libxml/parser.h>
#include <libxml/tree.h>
#include "xsd_handler.h"

namespace xmlgui {
    class XSDReader {
        public:
        static XSDHandler read_xsd(const std::filesystem::path& file);
    };
}
