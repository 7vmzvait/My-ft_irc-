/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   channel.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haitaabe <haitaabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/29 12:59:48 by haitaabe          #+#    #+#             */
/*   Updated: 2026/04/09 11:09:41 by haitaabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHANNEL_HPP
#define CHANNEL_HPP


#include <iostream>
#include <map>
#include <vector>
#include "../include/client.hpp"
#include "../include/server.hpp"


class Channel 
{
    private:
        std::string _name;
        std::string _topic;
        std::string _password;
        unsigned int _userLimit;
        bool _isInviteOnly;
        bool _isTopicRestricted;
        std::map<int, client*> _members;
        std::map<int, client*> _operators;

    public:
        Channel(std::string name);
        ~Channel();

        void addMember(client* user);
        void removeMember(int fd);
        void broadcast(std::string message, int excludeFd);
        bool isOperator(int fd);
};




#endif