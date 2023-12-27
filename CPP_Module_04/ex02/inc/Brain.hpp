/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbernar <clbernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 13:01:31 by clbernar          #+#    #+#             */
/*   Updated: 2023/12/27 14:48:20 by clbernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __BRAIN__HPP
#define __BRAIN__HPP

#include <string>

class Brain
{
	public:
	Brain();
	Brain(Brain const& asign);
	~Brain();

	Brain & operator=(Brain const & equal);
	std::string	getIdeas(int index) const;
	void		affectIdeas(std::string const to_affect, int index);

	private:
	std::string	m_ideas[100];
};

#endif
