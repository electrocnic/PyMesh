/* This file is part of PyMesh. Copyright (c) 2015 by Qingnan Zhou */
#pragma once

#include <string>

#include "MeshAttribute.h"

namespace PyMesh {

class VertexNormalAttribute : public MeshAttribute {
    public:
        virtual ~VertexNormalAttribute() = default;

    public:
        virtual void compute_from_mesh(Mesh& mesh) override;

    private:
        void compute_vertex_normals_from_face(Mesh& mesh);
        void compute_vertex_normals_from_edge(Mesh& mesh);
        const VectorF& get_attribute(Mesh& mesh, const std::string& attr_name);
};

}
