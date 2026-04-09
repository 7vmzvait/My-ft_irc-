/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   managerchannel.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haitaabe <haitaabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/09 11:04:57 by haitaabe          #+#    #+#             */
/*   Updated: 2026/04/09 11:09:24 by haitaabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MANAGERCHANNEL_HPP
#define MANAGERCHANNEL_HPP

#include <map>
#include <string>
#include "channel.hpp"

class managerchannel 
{
    private:
        std::map<std::string, Channel*> _allChannels;

    public:
        managerchannel();
        ~managerchannel();

        void handleJoin(client* user, std::string channelName);

        // void handlePart(client* user, std::string channelName);
        // void handlePrivmsg(client* user, std::string target, std::string message);
};

#endif