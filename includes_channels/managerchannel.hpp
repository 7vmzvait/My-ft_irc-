/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   managerchannel.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haitaabe <haitaabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/09 11:04:57 by haitaabe          #+#    #+#             */
/*   Updated: 2026/04/10 19:40:26 by haitaabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MANAGERCHANNEL_HPP
#define MANAGERCHANNEL_HPP

#include <map>
#include <string>
#include <vector>
#include "channel.hpp"

struct client; 

class managerchannel 
{
    private:
        std::map<int, client> &_clients;
        std::string _serverPassword;

        std::map<std::string, Channel*> _allChannels;

    public:
        managerchannel(std::map<int, client> &clients, const std::string &pass);
        ~managerchannel();

        void handle_input(const std::string &input, client &c); // done

        void handlePass(client *c, const std::string &password); //done
        void handleNick(client *c, const std::string &nickname); // done
        
        void handleUser(client *c, const std::vector<std::string> &tokens);
        
        void checkRegistrationComplete(client *c);
        void handleJoin(client* c, std::string channelName);
        
};

#endif