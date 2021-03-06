/*PGR-GNU*****************************************************************
 *

Copyright (c) 2015 Celia Virginia Vergara Castillo
vicky_vergara@hotmail.com

------

This program is free software; you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation; either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.

********************************************************************PGR-GNU*/

#ifndef SRC_COMMON_SRC_BASIC_VERTEX_H_
#define SRC_COMMON_SRC_BASIC_VERTEX_H_
#pragma once

#include <vector>

#include "./pgr_types.h"


namespace pgrouting {

class Basic_vertex {
 public:
     Basic_vertex() :
         id(0) {}
     Basic_vertex(const Basic_vertex &v) :
         id(v.id) {}

     explicit Basic_vertex(const int64_t _id) :
         id(_id) {}

     Basic_vertex(const pgr_edge_t &other, bool is_source) :
         id(is_source? other.source : other.target) {}

     void cp_members(const Basic_vertex &other) {
         this->id = other.id;
     }


     friend std::ostream& operator<<(std::ostream& log, const Basic_vertex &v);
 public:
     int64_t id;
};

size_t check_vertices(std::vector < Basic_vertex > vertices);


std::vector < Basic_vertex > extract_vertices(
        std::vector < Basic_vertex > vertices,
        const pgr_edge_t *data_edges, int64_t count);

std::vector < Basic_vertex > extract_vertices(
        std::vector < Basic_vertex > vertices,
        const std::vector < pgr_edge_t > data_edges);

std::vector < Basic_vertex > extract_vertices(
        const pgr_edge_t *data_edges, int64_t count);

std::vector < Basic_vertex > extract_vertices(
        const std::vector < pgr_edge_t > data_edges);


}  // namespace pgrouting

#endif  // SRC_COMMON_SRC_BASIC_VERTEX_H_
