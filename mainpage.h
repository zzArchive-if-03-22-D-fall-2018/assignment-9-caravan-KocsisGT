/** @file mainpage.h
* @brief Beschreibung von Karawane.
*/ 
/** @mainpage Caravan
*
* @author Peter Bauer / Gerald K&ouml;ck
*
* @section intro Einf&uuml;hrung
* Es ist ein Programm zu erstellen, mit dem Karawansereien in Zukunft ihre Karawanen elektronisch
* kontrollieren m&ouml;chten. Eine Karawane besteht aus einer Anzahl Packtiere (PackAnimal). Dies k&ouml;nnen
* entweder Kamele (Camel) oder Pferde (Horse) sein. Diese Kamele und Pferde haben folgende
* Eigenschaften:
* <dl>
* <dt>AnimalType type</dt>
* <dd> Entweder Kamel (Camel) oder Pferd (Horse).</dd>
*
* <dt>char *name</dt>
* <dd> Der Name des Tieres.</dd>
*
* <dt>int max_speed</dt>
* <dd> Die Anzahl Meilen, die ein Tier unbeladen pro Stunde zur&uuml;cklegt. Diese Gr&ouml;&szlig;e ist
* unver&auml;nderlich. Ein Kamel darf ein max. Geschwindigkeit von 20 haben; Pferde hingegen eine max.
* Geschwindigkeit von 50.</dd>
*
* <dt>int load</dt>
* <dd> Die Anzahl der Ballen, die ein Tier im Moment tr&auml;gt. Allerdings reduziert sich bei einem
* Kamel die tats&auml;chliche Reisegeschwindigkeit gegen&uuml;ber der maximalen Marschgeschwindigkeit um 1
* f&uuml;r jeden Ballen, das das Kamel tragen muss. Bei Pferden reduziert sich die tats&auml;chliche
* Reisegeschwindigkeit um 10 pro Ballen, die das Pferd tragen muss. Bei load > maxPace lassen
* sich sowohl Kamele als auch Pferde nieder und stehen nicht mehr auf.</dd>
*
* <dt>Caravan *my_caravan</dt>
* <dd> Zus&auml;tzlich muss noch jedes Tier wissen, zu welcher Karawane es geh&ouml;rt. Kann auch direkt
* ge&auml;ndert werden. Geh&ouml;rt dabei das Tier vor der Zuweisung zu einer anderen Karawane wird es nat&uuml;rlich
* dort ausgekettet.</dd>
* </dl>
*
* Beim Anlegen eines Tieres werden sein Name (name) und seine maximale Marschgeschwindigkeit
* (max_speed) &uuml;bergeben. Schon beim Anlegen wird - je nach Kamel oder Pferd - &uuml;berpr&uuml;ft, ob diese
* max. Marschgeschwindigkeit nicht zu hoch oder zu niedrig (< 0) ist. Im Fehlerfall wird die
* Geschwindigkeit nach oben (max. Geschwindigkeit) oder nach unten (0) korrigiert.
* Eine Karawane (Caravan) bildet mit den Packtieren eine logische Liste. Die Reisegeschwindigkeit
* (caravan_speed()) der Karawane entspricht der Geschwindigkeit des langsamsten Tiers. &Uuml;ber
* caravan_load() erh&auml;lt man die Gesamtanzahl der Ballen, die von der Karawane transportiert werden.
* Es k&ouml;nnen Tiere in die Karawane aufgenommen werden (add_pack_animal()). Eingekettet wird dabei
* immer am Beginn der Karawane. Geh&ouml;rte das Tier bisher einer anderen Karawane an, ist es nat&uuml;rlich
* vorher aus dieser zu entfernen. Ein Tier kann nat&uuml;rlich nicht mehrmals in einer Karawane oder
* gleichzeitig in mehreren Karawanen vorkommen. Tiere k&ouml;nnen auch direkt aus der Karawane entfernt
* werden, indem ihr Property MyCaravan auf eine andere Karawane oder null gesetzt wird.
*
* Die Tiere der Karawane k&ouml;nnen von ihrer Last befreit werden (unload()). Weiters kann die
* Last der Tiere so verteilt werden, dass die maximal m&ouml;gliche Geschwindigkeit der
* Karawane erzielt wird (optimize_load()).
*
* @section structure Die Struktur des Projekts
* Analog zur Grundstruktur der Aufgabenstellung, welche zwei Hauptentit&auml;ten (PackAnimal und
* Caravan) hat, teilt sich auch das Projekt zwei Teile auf:
* - Pack Animal Mit den Source Files pack_animal.c und pack_animal.h und den Test Files
* test_pack_animal.c und test_pack_animal.h.
*
* - Caravan Mit den Source Files caravan.c und caravan.h und den Test Files
* test_caravan.c und test_caravan.h.
*
* Die restlichen Files sind die aus den bisherigen Projekten bekannten Files. Starten Sie Ihre
* Arbeit mit der Implementierung der Funktionen f&uuml;r pack_animal.c, da caravan.c auf diese
* aufbaut.
*
* <strong>
* - Achten Sie darauf, dass Sie beim Entfernen von Tieren aus der Karawane
* immer die Nodes der Tiere l&ouml;schen, d.h., keine Memory Leaks hinterlassen.
* - Achten Sie weiters darauf, dass Sie nachdem Sie Speicher am Heap allokiert haben,
* immer die G&uuml;ltigkeit des Pointers auf diesen Speicher pr&uuml;fen.
</strong>
*/