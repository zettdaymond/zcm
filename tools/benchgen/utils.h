#pragma once

#include <filesystem>
#include <random>
#include <fstream>
#include <sstream>

#include <fmt/format.h>

#include "snippets.h"

namespace fs = std::filesystem;

const std::string funcSourceTemplate =
"void func{}()\n";

const std::string funcHeaderTemplate =
"void func{}();\n";

const std::string funcInvocationTemplate =
"func{}();\n";


inline void removeExistedFile(const fs::path& headerFilePath)
{
    if ( fs::exists(headerFilePath) ) {
        fmt::print("file {} is already exists and will be eraced...\n", headerFilePath.string());
        fs::remove(headerFilePath);
    }
}


inline auto generateContent(int startsWithNumber, int totalFuncCount) -> std::tuple<std::string, std::string, std::string>
{
    std::stringstream invocations;
    std::stringstream header;
    std::stringstream source;

    constexpr auto maxPerFunctionSnippets = 5u;
    //constexpr auto minPerFunctionSnippets = 1u;

    header << "#pragma once\n\n";

    //for each function
    for(std::size_t i = startsWithNumber; i < totalFuncCount + startsWithNumber; i++) {

        //gen snippets for function
        std::stringstream functionCode;

        auto totalSnippetsInFunction = (std::rand() % maxPerFunctionSnippets) + 1;

        for(std::size_t i = 0; i < totalSnippetsInFunction; i++) {
            auto snipetPos = std::rand() % std::size(snippents);
            functionCode << snippents[snipetPos];
        }

        source << fmt::format(funcSourceTemplate, i) << "{\n" << functionCode.str() << "\n" << "}\n\n";

        header << fmt::format(funcHeaderTemplate, i);
        invocations << fmt::format(funcInvocationTemplate, i);
    }

    return { invocations.str(), header.str(), source.str() };
}

inline std::string generateMainSource(const std::string includes, const std::string& funcCode)
{
//    constexpr auto mainTemplate =
//            "void main() { \n"
//            "{}"
//            "\n"
//            "}\n";

    std::stringstream mainSource;

    mainSource << includes;
    mainSource << "int main() { \n" << funcCode << "return 0;\n}\n";

    return mainSource.str();
}

inline void writeToFile(const fs::path& path, const std::string& content)
{
    //TODO: add checks
    std::ofstream output(path.string());

    output << content << "\n";

    output.flush();
    output.close();
}
