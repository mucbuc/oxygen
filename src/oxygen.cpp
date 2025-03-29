#include "oxygen.hpp"

#include <text_utils/text_utils.hpp>

namespace oxygen {

TextFactory::TextFactory(std::string temp)
    : m_template(temp)
    , m_variables()
{
}

TextFactory& TextFactory::set_var(std::string name, std::string value)
{
    m_variables[name] = value;
    return *this;
}

TextFactory& TextFactory::set_var(std::string name, const char* value)
{
    m_variables[name] = std::string(value);
    return *this;
}

TextFactory& TextFactory::set_vars(std::map<std::string, std::string> overrides)
{
    overrides.insert(m_variables.begin(), m_variables.end());
    std::swap(m_variables, overrides); 
    return *this;
}

std::string TextFactory::make(std::map<std::string, std::string> overrides) const
{
    overrides.insert(m_variables.begin(), m_variables.end());
    return text_utils::apply_variables(m_template, overrides);
}

#pragma mark-- ElementFactories

ElementFactories& ElementFactories::insert(std::string name, const TextFactory& f)
{
    m_factories.insert(std::make_pair(name, f));
    return *this;
}

const TextFactory& ElementFactories::factory(std::string name) const
{
    ASSERT(m_factories.find(name) != m_factories.end());
    return m_factories.at(name);
}

#pragma mark-- Menu

Menu::Menu(const ElementFactories& f)
    : m_element_factory(f)
{
}

const TextFactory& Menu::factory(std::string name) const
{
    return m_element_factory.factory(name);
}

}
