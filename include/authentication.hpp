/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   authentication.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haitaabe <haitaabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/21 02:45:56 by eazmir            #+#    #+#             */
/*   Updated: 2026/04/11 18:38:53 by haitaabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AUTHENTICATION_HPP
#define AUTHENTICATION_HPP

#include "server.hpp"

struct client;

class authentication
{
    private:
        std::string _serverPassword;
        
    public:
    authentication();
    authentication(std::string pass);
    void handlePass(client &client, const std::string &pass);
    void handleNick(client &client, const std::string &nick);
    void handleUser(client &client, const std::string &user);
    void tryRegister(client &client,const std::string &input);
    void checkRegistration(client &c);
    void send_welcome(client &c);
    std::string Extract_data(const std::string &data);
};
#endif
