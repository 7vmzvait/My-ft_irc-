/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haitaabe <haitaabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/11 10:00:14 by haitaabe          #+#    #+#             */
/*   Updated: 2026/04/11 18:37:56 by haitaabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/client.hpp"
#include "../include/utls.hpp"

managerchannel::managerchannel(std::map<int, client> &clients,const std::string &pass)
    : _clients(clients),
      auth(pass)
{
}

void managerchannel::handle_input(const std::string &input, client &c)
{
    if (!c.regestred)
    {
        this->auth.tryRegister(c,input);
        return;
    }
    if (input.compare(0, 4, "JOIN") == 0)
    {
        
    }
    else if (input.compare(0,5,"PRINT") == 0)
        Utils::printClientsInfo(_clients);
}