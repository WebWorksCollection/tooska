#ifndef JSON_SERIALIZER_H
#define JSON_SERIALIZER_H

#include "../global.h"
#include "../json/json_object.h"
#include "serializer_base.h"

TOOSKA_BEGIN_NAMESPACE(serialization)

class json_serializer : public serializer_base
{
    tooska::json::object *_object;
public:
    json_serializer();
    json_serializer(tooska::json::object *obj);

public:
    bool has_key(const std::string &key) const override;
    void serialize_value(const std::string &name, const tooska::core::variant &value) override;
    void deserialize_value(const std::string &name, tooska::core::variant &value) override;

    void serialize_vector(const std::string &name, const tooska::core::variant_vector &vec) override;
    void deserialize_vector(const std::string &name, tooska::core::variant_vector &vec) override;

    void serialize_object(const std::string &name, serializable *object) override;
    void deserialize_object(const std::string &name, serializable *object) override;
    serializer_base *create_serializer(serializable *child) const override;
    tooska::json::object *object() const;

};

    TOOSKA_END_NAMESPACE

#endif // JSON_SERIALIZER_H
