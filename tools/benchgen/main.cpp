#include "iostream"
#include "filesystem"
#include "string"
#include <ctime>
#include "fmt/format.h"


/**
 * Задача - сгенерить N *.cpp файлов со случайными имплементациями функций,
 * и N *.h файлов с их прототипами.
 *
 * Затем сгенерить main.cpp где эти функции вызываются.
 *
 * функция имеет прототип:
 * void fooN(void);, где N некий номер
 */

#include "utils.h"

namespace fs = std::filesystem;

constexpr auto filecount = 100u;
constexpr auto funccount = 100u;

constexpr auto cppPreabule = R"(
#include "{}"

#ifndef GLM_VARIANT

#include "zcm/vec2.h"
#include "zcm/vec3.h"
#include "zcm/vec4.h"

#include "zcm/mat3.h"
#include "zcm/mat4.h"

#include "zcm/geometric.h"
#include "zcm/exponential.h"
#include "zcm/common.h"
#include "zcm/angle_and_trigonometry.h"

using namespace zcm;

#else

#include "glm/vec2.hpp"
#include "glm/vec3.hpp"
#include "glm/vec4.hpp"

#include "glm/mat3.h"
#include "glm/mat4.h"

#include "glm/geometric.hpp"
#include "glm/exponential.hpp"
#include "glm/common.hpp"
#include "glm/trigonometric.hpp"

using namespace glm;

#endif
)";

int main(int argc, char *argv[])
{
    if(argc != 2) {
        fmt::print("Please specify a folder as a cmd parameter.\n");
        std::exit(-1);
    }

    auto directoryPath = fs::path(argv[1]);
    if(fs::is_directory(directoryPath) == false) {
        fmt::print("Specified path '{}' is not a directory\n", directoryPath.string());
        std::exit(-1);
    }

    std::srand(unsigned(std::time(0)));

    //
    // Step 1: Generate *.cpp and *.h files
    //
    std::stringstream invocations;
    std::stringstream includes;
    std::stringstream cppFiles;

    for(auto i = 0u; i < filecount; i++) {

        auto cppFileName = std::string("file") + std::to_string(i) + ".cpp";
        auto cppFilePath = directoryPath / cppFileName;

        auto headerFileName = std::string("file") + std::to_string(i) + ".h";
        auto headerFilePath = directoryPath / headerFileName;

        fmt::print("Write {} and {} files ...\n", cppFileName, headerFileName);

        removeExistedFile(cppFilePath);
        removeExistedFile(headerFilePath);

        auto&& [invocationSource, header, source] = generateContent(i * funccount, funccount);

        source = fmt::format(cppPreabule, headerFileName) + source;

        writeToFile(headerFilePath, header);
        writeToFile(cppFilePath, source);

        invocations << invocationSource << "\n";
        includes << fmt::format("#include \"{}\"\n", headerFileName);

        cppFiles << cppFileName << " ";
    }

    //
    // Step 2: Generate main.cpp with function invocations
    //
    {
        fmt::print("Write main.cpp...\n");

        auto mainPath = directoryPath / "main.cpp";
        auto mainSource = generateMainSource(includes.str(), invocations.str());
        writeToFile(mainPath, mainSource);
    }

    //
    // Step 3: Generate glm and zcm build scripts.
    //
    {
        fmt::print("Write build scripts\n");

        {
            auto glmBuildPath = directoryPath / "glm-build.sh";
            auto glmBuildSource = std::string("#!/bin/bash\n time g++ -DGLM_VARIANT=1 -I /usr/include/ ") + " main.cpp " + cppFiles.str() + "-lgcov && rm a.out\n";
            writeToFile(glmBuildPath, glmBuildSource);
        }

        {
            auto zcmBuildPath = directoryPath / "zcm-build.sh";
            auto zcmBuildSource = std::string("#!/bin/bash\n time g++ ") + " main.cpp " + cppFiles.str() + "-I ../pr/zcm/src/ -L $ZCM_LIBRARY_PATH -l$ZCM_LIBRARY_NAME -lgcov && rm a.out\n";
            writeToFile(zcmBuildPath, zcmBuildSource);
        }
    }


    fmt::print("Done.\n");

    return 0;
}
