/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   managerchannel.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haitaabe <haitaabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/09 16:38:58 by haitaabe          #+#    #+#             */
/*   Updated: 2026/04/10 14:56:34 by haitaabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../includes_channels/channel.hpp"
#include "../includes_channels/managerchannel.hpp"

#include <sstream>
#include <vector>
#include <iostream>


void managerchannel::handle_input(const std::string &input, client &c)
{
    std::istringstream check_input(input);
    std::string token;

    std::vector<std::string> tokens;
    while (check_input >> token)
    {
        tokens.push_back(token);
    }

    if (tokens.empty())
        return ;

    if (!c.regestred)
    {
        if(tokens[0] == "PASS")
        {
            if (tokens.size() > 1)
                handlePass(&c, tokens[1]);
        }
    }
}

void managerchannel::handlePass(client *c, const std::string &password)
{
    if (c->regestred)
    {
        std::cout << "Error: User is already registered!" << std::endl;
        return;
    }

    if (password == _serverPassword)
    {
        c->pass_ok = true;
    }
    
    else 
    {
        c->pass_ok = false;
    }
}