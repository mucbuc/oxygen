#include "oxygen.hpp"

#include <text_utils/text_utils.hpp>

namespace oxygen {

	TextFactory::TextFactory(std::string temp)
	: m_template(temp)
	{}

	TextFactory & TextFactory::set_var(std::string name, std::string value)
	{
		m_variables[name] = value;
		return * this;
	}

	TextFactory & TextFactory::set_var(std::string name, const char * value)
	{
		m_variables[name] = std::string(value);
		return * this;
	}

	TextFactory & TextFactory::set_vars(std::initializer_list<typename std::map<std::string, std::string>::value_type > init_list)
	{
		for (auto p : init_list) {
			m_variables[p.first] = p.second; 
		}
		return * this;
	}

	std::string TextFactory::make(std::initializer_list<typename std::map<std::string, std::string>::value_type> init_list) const
	{
		std::map<std::string, std::string> variables( init_list );

		for (auto p : m_variables) {
			variables.emplace(p); 
		}

		return text_utils::apply_variables(m_template, variables); 
	}

#pragma mark -- ElementFactories

	ElementFactories & ElementFactories::insert(std::string name, const TextFactory & f)
	{
		const auto r = m_factories.insert(make_pair(name, f));
		return * this;
	}
	
	const TextFactory & ElementFactories::factory(std::string name) const
	{
		ASSERT(m_factories.find(name) != m_factories.end());
		return m_factories.at(name);
	}

#pragma mark -- Menu

	Menu::Menu(const ElementFactories & f)
	: m_element_factory(f)
	{

	}

	const TextFactory & Menu::factory(std::string name) const
	{
		return m_element_factory.factory(name); 
	}




}
