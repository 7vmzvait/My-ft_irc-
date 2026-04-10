/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   managerchannel.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haitaabe <haitaabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/09 16:38:58 by haitaabe          #+#    #+#             */
/*   Updated: 2026/04/10 19:41:09 by haitaabe         ###   ########.fr       */
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

void managerchannel::handleNick(client *c, const std::string &nickname)
{
    if (c->regestred)
    {
        std::cout << "Error: User already registered!" << std::endl;
        return ;
    }

    
    std::map<int, client>::iterator it;
    
    for (it = _clients.begin(); it != _clients.end(); ++it)
    {
        if (it->second.nickname == nickname)
        {
            std::cout << "You cannot use this name, it used , GOTTA CHANGE IT!" << std::endl;
            return ;   
        }
    }
    
    c->nickname = nickname;
    c->nick_ok = true;
}


void managerchannel::handleUser(client *c, const std::vector<std::string> &tokens)
{
    if (c->regestred)
    {
        std::cout << "Error: User already registered!" << std::endl;
        return;
    }

    if (tokens.size() < 5)
    {
        std::cout << "Not enough info!" << std::endl;
        return;
    }
}