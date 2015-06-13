/*
 * Engine.hpp
 *
 *  Created on: 13 Jun 2015
 *      Author: Michał Orynicz
 */

#ifndef SRC_ENGINE_HPP_
#define SRC_ENGINE_HPP_

#include <list>

/**
 * \brief The app engine providing groups and amount of conteders exiting the groups
 */
class Engine {
public:
    Engine();
    std::list<std::pair<int, int>> generateGroups(const int &copetitorCount,
            const int &time, const int &length, const int &parallel) const;
    virtual ~Engine();
};

#endif /* SRC_ENGINE_HPP_ */
