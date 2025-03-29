#pragma once

#include "oxygen.hpp"

namespace oxygen {

ElementFactories html_factory()
{
    ElementFactories result;

    auto button_factory = TextFactory(R"(
        <button type="{{type}}">{{content}}</button>
    )")
                              .set_var("type", "submit");

    result.insert("button", button_factory);

    auto radio_button_factory = TextFactory(R"(
        <div>
            <input type="{{type}}" id="{{id}}" name="{{name}}" value="{{value}}" {{checked}}/>
            <label for="{{id}}">{{label}}</label>
        </div>
    )")
                                    .set_vars({
                                        { "checked", "" },
                                        { "type", "radio" },
                                    });
    result.insert("radio_button", radio_button_factory);

    auto form_factory = TextFactory(R"(
        <form action="{{action}}">
        {{content}}
        {{submit}}
        </form>
    )")
                            .set_var("submit", "");
    result.insert("form", form_factory);

    return result;
}

}