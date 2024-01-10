//
// Created by arthur on 10/01/2024.
//

#ifndef CONCERTO_EDITOR_EXPORT_HPP
#define CONCERTO_EDITOR_EXPORT_HPP

#include <Concerto/Core/Types.hpp>

#ifdef CONCERTO_EDITOR_BUILD
    #define CONCERTO_EDITOR_API CONCERTO_EXPORT
#else
    #define CONCERTO_EDITOR_API CONCERTO_IMPORT
#endif

#endif //CONCERTO_EDITOR_EXPORT_HPP
