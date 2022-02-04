#pragma once

#include <ls3p/messages/common.hpp>
#include <ls3p/messages/TextEdit.hpp>

namespace ls3p::messages
{

using ChangeAnnotationIdentifier = std::string;

struct AnnotatedTextEdit : TextEdit
{
    ChangeAnnotationIdentifier annotation_id;
};

}