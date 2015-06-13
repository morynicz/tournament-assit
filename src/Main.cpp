/*
 * Main.cpp
 *
 *  Created on: 13 Jun 2015
 *      Author: link
 */

#include <boost/program_options.hpp>

#include "Engine.hpp"

static void parseCommandline(const int &argc, char **argv, int &competitorCount,
        int &time, int &length) {

    boost::program_options::options_description desc;

    desc.add_options()("help,h", "this help message")("competitor_count,c",
            boost::program_options::value<int>(),
            "number of competitors taking part in tournament")("time,t",
            boost::program_options::value<int>(),
            "amount of time for round robin phase")("length,l",
            boost::program_options::value<int>(),
            "length of a single round/fight");
    boost::program_options::variables_map vm;
    boost::program_options::store(
            boost::program_options::parse_command_line(argc, argv, desc), vm);
    boost::program_options::notify(vm);

    if (vm.count("help")) {
        std::cout << desc << std::endl;
        throw USER_TRIGGERED_EXIT;
    }

    if (vm.count("competitor_count")) {
        competitorCount = vm["competitor_count"].as<int>();
    }

    if (vm.count("time")) {
        time = vm["time"].as<int>();
    }

    if (vm.count("length")) {
        length = vm["length"].as<int>();
    }
}

int main(const int &argc, char **argv) {
    int competitorCount;
    int time;
    int length;

    parseCommandline(argc, argv, competitorCount, time, length);

    return 0;
}
