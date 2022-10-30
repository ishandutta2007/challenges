/*

Currently, the Stack Exchange network has nearly 150 sites. These sites are as follows:

Computer Graphics
Portuguese Language
elementary OS
Open Source
Law
Русский язык
Mythology
Health
Stack Overflow на русском
CiviCRM
Woodworking
Music Fans
Vi and Vim
Coffee
Engineering
Lifehacks
Economics
History of Science and Mathematics
Emacs
スタック・オーバーフロー
Worldbuilding
Startups
Community Building
Hinduism
Buddhism
Craft CMS
Puzzling
Data Science
Joomla
Earth Science
Mathematics Educators
Expatriates
Arduino
Software Recommendations
Beer
Ebooks
Aviation
Stack Overflow em Português
Italian Language
Amateur Radio
Pets
Tor
Astronomy
Space Exploration
Blender
Freelancing
Open Data
Network Engineering
Reverse Engineering
Tridion
Sustainable Living
English Language Learners
Magento
Anime & Manga
Politics
ExpressionEngine® Answers
Robotics
Genealogy & Family History
Ask Patents
Salesforce
Islam
Russian Language
Raspberry Pi
Chess
Chemistry
Windows Phone
The Workplace
Computer Science
Academia
Sports
Martial Arts
The Great Outdoors
Cognitive Sciences
Mathematica
Poker
Biology
Chinese Language
Movies & TV
Computational Science
Spanish Language
LEGO® Answers
History
Biblical Hermeneutics
Linguistics
Bitcoin
Christianity
French Language
Signal Processing
Cryptography
Personal Productivity
Travel
Gardening & Landscaping
Philosophy
Japanese Language
German Language
Mi Yodeya
Software Quality Assurance & Testing
Music: Practice & Theory
SharePoint
Parenting
Motor Vehicle Maintenance & Repair
Drupal Answers
Physical Fitness
Skeptics
Project Management
Quantitative Finance
Programming Puzzles & Code Golf
Code Review
Science Fiction & Fantasy
Graphic Design
Database Administrators
Video Production
Writers
Information Security
Sound Design
Homebrewing
Physics
Board & Card Games
Electrical Engineering
Android Enthusiasts
Programmers
Bicycles
Role-playing Games
Ask Different
Theoretical Computer Science
WordPress Development
Unix & Linux
User Experience
English Language & Usage
Personal Finance & Money
Ask Ubuntu
TeX - LaTeX
Geographic Information Systems
Home Improvement
Mathematics
Cross Validated
Photography
Game Development
Seasoned Advice
Webmasters
Arqade
Web Applications
Stack Apps
MathOverflow
Super User
Meta Stack Exchange
Server Fault
Stack Overflow

Your Task:
Write a program that prints out all of the sites in Stack Exchange, including those with non-ASCII characters (It doesn't need to be in any specific order).
The program must accept no input, and must output each site on its own line (optional leading/trailing newlines).
No standard loopholes.
This is code-golf, so the shortest program, measured in bytes, wins.

*/

package main

import "fmt"

func main() {
	fmt.Println(sites)
}

const sites = `Computer Graphics
Portuguese Language
elementary OS
Open Source
Law
Русский язык
Mythology
Health
Stack Overflow на русском
CiviCRM
Woodworking
Music Fans
Vi and Vim
Coffee
Engineering
Lifehacks
Economics
History of Science and Mathematics
Emacs
スタック・オーバーフロー
Worldbuilding
Startups
Community Building
Hinduism
Buddhism
Craft CMS
Puzzling
Data Science
Joomla
Earth Science
Mathematics Educators
Expatriates
Arduino
Software Recommendations
Beer
Ebooks
Aviation
Stack Overflow em Português
Italian Language
Amateur Radio
Pets
Tor
Astronomy
Space Exploration
Blender
Freelancing
Open Data
Network Engineering
Reverse Engineering
Tridion
Sustainable Living
English Language Learners
Magento
Anime & Manga
Politics
ExpressionEngine® Answers
Robotics
Genealogy & Family History
Ask Patents
Salesforce
Islam
Russian Language
Raspberry Pi
Chess
Chemistry
Windows Phone
The Workplace
Computer Science
Academia
Sports
Martial Arts
The Great Outdoors
Cognitive Sciences
Mathematica
Poker
Biology
Chinese Language
Movies & TV
Computational Science
Spanish Language
LEGO® Answers
History
Biblical Hermeneutics
Linguistics
Bitcoin
Christianity
French Language
Signal Processing
Cryptography
Personal Productivity
Travel
Gardening & Landscaping
Philosophy
Japanese Language
German Language
Mi Yodeya
Software Quality Assurance & Testing
Music: Practice & Theory
SharePoint
Parenting
Motor Vehicle Maintenance & Repair
Drupal Answers
Physical Fitness
Skeptics
Project Management
Quantitative Finance
Programming Puzzles & Code Golf
Code Review
Science Fiction & Fantasy
Graphic Design
Database Administrators
Video Production
Writers
Information Security
Sound Design
Homebrewing
Physics
Board & Card Games
Electrical Engineering
Android Enthusiasts
Programmers
Bicycles
Role-playing Games
Ask Different
Theoretical Computer Science
WordPress Development
Unix & Linux
User Experience
English Language & Usage
Personal Finance & Money
Ask Ubuntu
TeX - LaTeX
Geographic Information Systems
Home Improvement
Mathematics
Cross Validated
Photography
Game Development
Seasoned Advice
Webmasters
Arqade
Web Applications
Stack Apps
MathOverflow
Super User
Meta Stack Exchange
Server Fault
Stack Overflow`
