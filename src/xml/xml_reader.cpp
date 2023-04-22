#include "xml_reader.h"
#include <vector>
// #include <libxml/xmlreader.h>

namespace xmlgui {
    namespace {
            Node SpawnInputActionNode()
            {
                Node node(Counter::GetNextId(), "InputAction Fire", ImColor(255, 128, 128));
                node.Outputs.emplace_back(Counter::GetNextId(), "", PinType::Delegate);
                node.Outputs.emplace_back(Counter::GetNextId(), "Pressed", PinType::Flow);
                node.Outputs.emplace_back(Counter::GetNextId(), "Released", PinType::Flow);

                // BuildNode(&node);
                node.assemble();

                return std::move(node);
            }
    }
    std::vector<Node> XMLReader::read_xml(const std::filesystem::path& file) {
        return {SpawnInputActionNode()};
    }
}