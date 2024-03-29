#pragma once
#include <filesystem>
#include "../node.h"

namespace xmlgui {
    class XMLReader {
        public:
        static std::vector<Node> read_xml(const std::filesystem::path& xml_file,
                                          const std::filesystem::path& xsd_file);
    };
}
